/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1011.在-d-天内送达包裹的能力.cpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taoyanqi <taoyanqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/31 by taoyanqi                        #+#    #+#             */
/*   Updated: 2026/08/31 by taoyanqi                        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// 1011. 在 D 天内送达包裹的能力
// 二分答案：最小的运力 cap 使 D 天内运完，check(cap) = 按序贪心装船的天数 <= days
class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        auto check = [&](int cap) {         // 以运力 cap 能否在 days 天内运完
            int need = 1;                   // 至少一天
            long long cur = 0;
            for (int w : weights) {
                if (cur + w > cap) { need++; cur = 0; }  // 装不下，新开一天
                cur += w;
            }
            return need <= days;
        };
        int left = *max_element(weights.begin(), weights.end());   // 单件必须装得下
        int right = accumulate(weights.begin(), weights.end(), 0); // 一天全运走
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (check(mid)) right = mid;
            else left = mid + 1;
        }
        return left;
    }
};
