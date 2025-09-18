/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1679. K 和数对的最大数目.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taoyanqi <taoyanqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 09:29:48 by taoyanqi          #+#    #+#             */
/*   Updated: 2025/09/18 09:29:51 by taoyanqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int res = 0;
        unordered_map<int, int> mp;
        for(auto x: nums) {
            if(mp.count(k - x)) {
                res++;
                mp[k - x]--;
                if(mp[k - x] == 0) mp.erase(k - x);
            }
            else mp[x]++;
        }
        return res;
    }
};