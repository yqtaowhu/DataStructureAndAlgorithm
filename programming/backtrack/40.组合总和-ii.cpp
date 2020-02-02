/*
 * @lc app=leetcode.cn id=40 lang=cpp
 *
 * [40] 组合总和 II
 */

// @lc code=start
class Solution {
public:
    void dfs(vector<vector<int> > &res, vector<int> &candidates, vector<int> &comb, int target, int beg) {
        if(target == 0) {
            res.push_back(comb);
            return;
        }
        // dfs
        for(int i=beg; i<candidates.size() && target >= candidates[i]; i++) {
            // 注意写法，不使用重复的元素
            if(i==beg || candidates[i] != candidates[i-1]) {
                comb.push_back(candidates[i]);
                // 注意i+1,每个元素只能使用一次
                dfs(res, candidates, comb, target-candidates[i], i+1);
                // 回溯
                comb.pop_back();
            }
        }
    }
    vector<vector<int> > combinationSum2(vector<int>& candidates, int target) {
       sort(candidates.begin(), candidates.end());
       vector<vector<int> > res;
       vector<int> comb;
       dfs(res, candidates,comb, target, 0);
       return res;
    }
};
// @lc code=end

