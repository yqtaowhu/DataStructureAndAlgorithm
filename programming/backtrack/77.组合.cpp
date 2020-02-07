/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
 */

// @lc code=start
class Solution {
public:
    void dfs(vector<vector<int>> &combs, vector<int> &comb, int n, int k, int beg) {
        if(comb.size() == k) {
            combs.push_back(comb);
            return;
        }
        for(int i=beg; i<=n; i++) {
            comb.push_back(i);
            dfs(combs, comb, n, k, i+1);
            comb.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> comb;
        vector<vector<int>> combs;
        dfs(combs, comb, n, k, 1);
        return combs;

    }
};
// @lc code=end

