/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1760.袋子里最少数目的球.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taoyanqi <taoyanqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/31 by taoyanqi                        #+#    #+#             */
/*   Updated: 2026/08/31 by taoyanqi                        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// 1760. 袋子里最少数目的球
// 二分惩罚值 x（单袋最大球数）：把 b 个球的袋子切到全部 <= x 需 ceil(b/x) - 1 次操作
// check(x) = 总操作数 <= maxOperations
class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        auto check = [&](long long x) {
            long long ops = 0;
            for (int b : nums) ops += (b - 1) / x;    // ceil(b/x) - 1
            return ops <= maxOperations;
        };
        long long left = 1, right = *max_element(nums.begin(), nums.end());
        while (left < right) {
            long long mid = left + (right - left) / 2;
            if (check(mid)) right = mid;
            else left = mid + 1;
        }
        return left;
    }
};
