/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2560.打家劫舍-iv.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taoyanqi <taoyanqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/31 by taoyanqi                        #+#    #+#             */
/*   Updated: 2026/08/31 by taoyanqi                        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// 2560. 打家劫舍 IV
// 二分窃取能力 cap：check(cap) = 金额 <= cap 的房子中（跳过相邻）贪心可偷间数 >= k
class Solution {
public:
    int minCapability(vector<int>& nums, int k) {
        auto check = [&](int cap) {         // cap 之内最多能偷几间
            int cnt = 0;
            for (int i = 0; i < (int)nums.size(); i++) {
                if (nums[i] <= cap) { cnt++; i++; }   // 偷这间就跳过下一间
            }
            return cnt >= k;
        };
        int left = *min_element(nums.begin(), nums.end());
        int right = *max_element(nums.begin(), nums.end());
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (check(mid)) right = mid;
            else left = mid + 1;
        }
        return left;
    }
};
