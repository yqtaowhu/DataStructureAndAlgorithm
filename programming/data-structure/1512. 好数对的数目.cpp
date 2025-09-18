/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1512. 好数对的数目.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taoyanqi <taoyanqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 09:21:17 by taoyanqi          #+#    #+#             */
/*   Updated: 2025/09/18 09:21:18 by taoyanqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int res = 0;
        unordered_map<int, int> mp;
        for(auto x : nums) {
            if(mp.find(x) != mp.end()) {
                res += mp[x];
            }
            mp[x]++;
        }
        return res;
        
    }
};