/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1283.使结果不超过阈值的最小除数.cpp                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taoyanqi <taoyanqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/31 by taoyanqi                        #+#    #+#             */
/*   Updated: 2026/08/31 by taoyanqi                        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// 1283. 使结果不超过阈值的最小除数
// 二分除数 d：check(d) = sum(ceil(nums[i]/d)) <= threshold（d 越大和越小）
class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        auto check = [&](int d) {
            long long sum = 0;
            for (int x : nums) sum += (x - 1) / d + 1;   // 上取整
            return sum <= threshold;
        };
        int left = 1, right = *max_element(nums.begin(), nums.end());
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (check(mid)) right = mid;
            else left = mid + 1;
        }
        return left;
    }
};
