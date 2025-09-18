/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0219. 存在重复元素 II.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taoyanqi <taoyanqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 09:24:33 by taoyanqi          #+#    #+#             */
/*   Updated: 2025/09/18 09:24:33 by taoyanqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

class Solution {
public:
    // 维护左，枚举右
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int size = nums.size();
        if(size < 2) return false;
        unordered_map<int, int> mp;
        for(int i = 0; i < size; i++) {
            if(mp.count(nums[i])) {
                if(i - mp[nums[i]] <= k) return true;
            }
            mp[nums[i]] = i;  // 更新边界
        }
        return false;
    }
};