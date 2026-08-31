/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0410.分割数组的最大值.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taoyanqi <taoyanqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/31 by taoyanqi                        #+#    #+#             */
/*   Updated: 2026/08/31 by taoyanqi                        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// 410. 分割数组的最大值
// 「最小化最大值」经典题：二分最大和 limit，check(limit) = 贪心分组段数 <= k
class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        auto check = [&](long long limit) { // 每段和 <= limit 时最多分出几段
            int cnt = 1;
            long long cur = 0;
            for (int x : nums) {
                if (cur + x > limit) { cnt++; cur = 0; }  // 超了，新开一段
                cur += x;
            }
            return cnt <= k;
        };
        long long left = *max_element(nums.begin(), nums.end());   // 单个元素是一段
        long long right = accumulate(nums.begin(), nums.end(), 0LL);
        while (left < right) {
            long long mid = left + (right - left) / 2;
            if (check(mid)) right = mid;
            else left = mid + 1;
        }
        return left;
    }
};
