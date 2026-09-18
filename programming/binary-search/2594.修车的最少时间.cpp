/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2594.修车的最少时间.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taoyanqi <taoyanqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/31 by taoyanqi                        #+#    #+#             */
/*   Updated: 2026/08/31 by taoyanqi                        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// 2594. 修车的最少时间
// 二分时间 t：rank r 的技师修 n 辆车要 r*n^2 分钟，故 t 分钟内能修 floor(sqrt(t/r)) 辆
// check(t) = 各技师产能之和 >= cars
class Solution {
public:
    long long repairCars(vector<int>& ranks, int cars) {
        auto check = [&](long long t) {
            long long cnt = 0;
            for (int r : ranks) {
                long long x = sqrtl((long double)t / r);
                while ((x + 1) * (x + 1) * r <= t) x++;   // 修正浮点误差
                while (x * x * r > t) x--;
                cnt += x;
                if (cnt >= cars) return true;             // 提前退出
            }
            return cnt >= cars;
        };
        long long left = 1;
        long long right = 1LL * *min_element(ranks.begin(), ranks.end()) * cars * cars;
        while (left < right) {
            long long mid = left + (right - left) / 2;
            if (check(mid)) right = mid;
            else left = mid + 1;
        }
        return left;
    }
};
