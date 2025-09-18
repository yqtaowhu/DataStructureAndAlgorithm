/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2441. 与对应负数同时存在的最大正整数.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taoyanqi <taoyanqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 09:20:32 by taoyanqi          #+#    #+#             */
/*   Updated: 2025/09/18 09:20:33 by taoyanqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

class Solution {
public:
    // 双变量问题
    // a[i] + a[j] = 0
    int findMaxK(vector<int>& nums) {
        int res = -1;
        unordered_map<int, int> mp;
        for(int j=0; j<nums.size(); j++) {
            if(mp.count(-nums[j])) {
                res = max(res, abs(nums[j]));
            }
            mp[nums[j]] = 1;
        }
        return  res;
    }
};