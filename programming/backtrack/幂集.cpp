/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   幂集.cpp                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taoyanqi <taoyanqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 21:02:11 by taoyanqi          #+#    #+#             */
/*   Updated: 2024/05/28 21:02:28 by taoyanqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// https://leetcode.cn/problems/power-set-lcci/description/?envType=study-plan-v2&envId=cracking-the-coding-interview
class Solution {
public:
    void dfs(vector<vector<int>> &res, vector<int>& nums, vector<int> &tmp, int beg) {
        res.push_back(tmp);
        for(int i=beg; i<nums.size(); i++) {
            tmp.push_back(nums[i]);
            dfs(res, nums, tmp, i+1);
            tmp.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> tmp;
        dfs(res, nums, tmp, 0);
        return res;
    }
};