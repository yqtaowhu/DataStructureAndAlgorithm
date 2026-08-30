/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2563.统计公平数对的数目.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taoyanqi <taoyanqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/30 by taoyanqi                        #+#    #+#             */
/*   Updated: 2026/08/30 by taoyanqi                        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// 2563. 统计公平数对的数目
// 排序后枚举每个 i，在 [i+1, n) 中用两次二分统计
// 满足 lower <= nums[i] + nums[j] <= upper 的 j 的个数
class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        // 排序不影响数对和，只影响枚举顺序
        sort(nums.begin(), nums.end());
        long long ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            // 从 i+1 开始搜，保证 j > i，避免重复计数和 i 自配
            auto l = lower_bound(nums.begin() + i + 1, nums.end(), lower - nums[i]);
            auto r = upper_bound(nums.begin() + i + 1, nums.end(), upper - nums[i]);
            ans += r - l;
        }
        return ans;
    }
};
