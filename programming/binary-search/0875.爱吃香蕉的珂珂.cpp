/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0875.爱吃香蕉的珂珂.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taoyanqi <taoyanqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/31 by taoyanqi                        #+#    #+#             */
/*   Updated: 2026/08/31 by taoyanqi                        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// 875. 爱吃香蕉的珂珂
// 二分答案：最小的速度 k 使 h 小时内吃完，check(k) = sum(ceil(p/k)) <= h
// check 关于 k 单调递减（k 越大越容易满足），套左闭右开模板找分界点
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        auto check = [&](int k) {           // 以速度 k 能否在 h 小时内吃完
            long long hours = 0;
            for (int p : piles) hours += (p - 1) / k + 1;   // 上取整防溢出
            return hours <= h;
        };
        int left = 1, right = *max_element(piles.begin(), piles.end());
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (check(mid)) right = mid;    // mid 可能是答案，不能丢
            else left = mid + 1;            // mid 太慢，一定不是答案
        }
        return left;
    }
};
