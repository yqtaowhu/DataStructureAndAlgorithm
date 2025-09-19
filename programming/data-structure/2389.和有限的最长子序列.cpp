/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2389.和有限的最长子序列.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taoyanqi <taoyanqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 17:11:41 by taoyanqi          #+#    #+#             */
/*   Updated: 2025/09/19 17:11:44 by taoyanqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(), nums.end());
        vector<int> f(nums.size()+1);
        for(int i = 0; i < nums.size(); i++) {
            f[i+1] = f[i] + nums[i];
        }
        vector<int> ans;
        for(int i = 0; i < queries.size(); i++) {
            int j = upper_bound(f.begin(), f.end(), queries[i]) - f.begin();
            ans.push_back(j-1);
        }
        return ans;
    }
};