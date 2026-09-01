/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1870.准时到达的列车最小时速.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taoyanqi <taoyanqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/31 by taoyanqi                        #+#    #+#             */
/*   Updated: 2026/08/31 by taoyanqi                        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// 1870. 准时到达的列车最小时速
// 二分答案（浮点版转整数）：中间 n-1 段向上取整整小时，最后一段可不足一小时
// 把时间放大 100 倍转成整数比较，彻底避开浮点精度问题
// 注意：最后一段与整数 target 比较时也必须上取整，否则会低估耗时（如 dist=[1,1,100000], hour=2.01）
class Solution {
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        long long target = llround(hour * 100);     // 允许的总时长（百分之一小时）
        int n = dist.size();
        if (target <= 100LL * (n - 1)) return -1;   // 中间每段至少 1 小时
        auto check = [&](long long speed) {         // 以 speed 能否准时到达
            long long t = 0;
            for (int i = 0; i < n - 1; i++) t += (dist[i] + speed - 1) / speed * 100;
            t += (dist[n - 1] * 100 + speed - 1) / speed;  // 最后一段也需上取整才能与整数 target 精确比较
            return t <= target;
        };
        long long left = 1, right = 10000000LL + 1; // 题目保证答案 <= 1e7
        while (left < right) {
            long long mid = left + (right - left) / 2;
            if (check(mid)) right = mid;
            else left = mid + 1;
        }
        return left > 10000000LL ? -1 : (int)left;
    }
};
