/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3152. 特殊数组 II.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taoyanqi <taoyanqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 17:07:09 by taoyanqi          #+#    #+#             */
/*   Updated: 2025/09/19 17:07:10 by taoyanqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

class Solution {
public:
    // 前缀和，思路要开阔
    // 如果相邻是特殊的，则为0， 否则为1， 构成前缀和，即可快速判断
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> preSum(nums.size());
        for(int i=1; i<nums.size(); i++) {
            preSum[i] = preSum[i-1] + (nums[i] % 2 == nums[i-1] % 2);
        }
        vector<bool> ans(queries.size());
        for(int i=0; i<queries.size(); i++) {
            auto& q = queries[i];
            ans[i] = preSum[q[0]] == preSum[q[1]];
        }
        return ans;
    }
};