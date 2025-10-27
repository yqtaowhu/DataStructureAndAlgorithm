/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0039.组合总和.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taoyanqi <taoyanqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 17:56:08 by taoyanqi          #+#    #+#             */
/*   Updated: 2025/10/27 17:56:08 by taoyanqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 */

// @lc code=start
#include<vector>
using namespace std;

class Solution {
public:
    void dfs(vector<vector<int> > &res, vector<int> &candidates, vector<int> &comb, int target, int beg) {
        if(target == 0) {
            res.push_back(comb);
            return;
        }
        // dfs
        for(int i=beg; i<candidates.size() && target >= candidates[i]; i++) {
            comb.push_back(candidates[i]);
            dfs(res, candidates, comb, target-candidates[i], i);
            // 回溯
            comb.pop_back();
        }
    }
    vector<vector<int> > combinationSum(vector<int>& candidates, int target) {
       sort(candidates.begin(), candidates.end());
       vector<vector<int> > res;
       vector<int> comb;
       dfs(res, candidates,comb, target, 0);
       return res;
    }
};
// @lc code=end

