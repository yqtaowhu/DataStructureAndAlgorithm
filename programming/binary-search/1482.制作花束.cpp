/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1482.制作花束.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taoyanqi <taoyanqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/31 by taoyanqi                        #+#    #+#             */
/*   Updated: 2026/08/31 by taoyanqi                        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// 1482. 制作花束
// 二分天数 day：check(day) = 连续 k 朵盛开的花能扎出的花束数 >= m
class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        if (1LL * m * k > (long long)bloomDay.size()) return -1;  // 花不够
        auto check = [&](int day) {         // 第 day 天能扎几束
            int bouquets = 0, adj = 0;
            for (int d : bloomDay) {
                adj = d <= day ? adj + 1 : 0;   // 维护连续开花的长度
                if (adj == k) { bouquets++; adj = 0; }
            }
            return bouquets >= m;
        };
        int left = *min_element(bloomDay.begin(), bloomDay.end());
        int right = *max_element(bloomDay.begin(), bloomDay.end());
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (check(mid)) right = mid;
            else left = mid + 1;
        }
        return left;
    }
};
