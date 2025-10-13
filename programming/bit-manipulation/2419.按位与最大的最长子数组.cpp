/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2419.按位与最大的最长子数组.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taoyanqi <taoyanqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 09:51:22 by taoyanqi          #+#    #+#             */
/*   Updated: 2025/10/10 09:51:22 by taoyanqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxValue = nums[0];
        int ans = 1, cnt = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > maxValue) {
                ans = cnt = 1;
                maxValue = nums[i];
            } else if (nums[i] < maxValue) {
                cnt = 0;
            } else if (nums[i] == maxValue) {
                cnt++;
            }
            ans = max(cnt, ans);
        }
        return ans;
    }
};