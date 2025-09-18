/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0001.两数之和.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taoyanqi <taoyanqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 09:19:35 by taoyanqi          #+#    #+#             */
/*   Updated: 2025/09/18 09:19:46 by taoyanqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        // a_i + a_j = target
        // 枚举j，找a[i]+ a[j] = target
        for(int j=0; j<nums.size(); j++) {
            auto it = mp.find(target - nums[j]);
            if(it != mp.end()) {
                return vector<int> {it->second, j};
            }
            mp[nums[j]] = j;
        }
        return vector<int>{-1, -1};
    }
};