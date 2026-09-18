/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0930.和相同的二元子数组.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taoyanqi <taoyanqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 12:34:39 by taoyanqi          #+#    #+#             */
/*   Updated: 2025/09/22 12:35:02 by taoyanqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        // 1 0 1 0 1
        // 0:1 1 : 1 2 : 1
        unordered_map<int, int> hash;
        int ans = 0, s = 0;
        for(auto x : nums) {
            hash[s]++;
            s += x;
            ans += hash.count(s-goal) ? hash[s-goal] : 0;
        }
        return ans;
        
    }
};
