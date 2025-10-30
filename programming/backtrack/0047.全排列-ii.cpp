/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0047.全排列-ii.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taoyanqi <taoyanqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 09:15:26 by taoyanqi          #+#    #+#             */
/*   Updated: 2025/10/30 09:16:35 by taoyanqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

class Solution {
public:

    vector<vector<int>> res;
    vector<int> tmp;

    void backtrace(vector<int>&nums, vector<int>&vis) {
        if(tmp.size() == nums.size()) {
            res.push_back(tmp);
            return;
        }
        // 每次都是从0开始的
        for(int i=0; i < nums.size(); i++) {
            if(vis[i] != 1) {
                // 上一个重复的值未被使用
                if (i > 0 && nums[i] == nums[i - 1] && vis[i - 1] != 1) {
                    continue;
                }
                tmp.push_back(nums[i]);
                vis[i] = 1;
                backtrace(nums, vis);
                tmp.pop_back();
                vis[i] = 0;
            }
        }
        return;
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> vis(nums.size(), 0);
        backtrace(nums, vis);
        return res;
        
    }
};