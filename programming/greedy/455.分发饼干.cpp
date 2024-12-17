/*
 * @lc app=leetcode.cn id=455 lang=cpp
 *
 * [455] 分发饼干
 */

// @lc code=start
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int g_size = g.size(), s_size = s.size();
        int g_idx = 0, s_idx = 0;
        while(g_idx < g_size && s_idx < s_size) {
            // 满足需求
            if(g[g_idx] <= s[s_idx]) {
                g_idx += 1;
            }
            s_idx += 1;
        }
        return g_idx;
    }
};
// @lc code=end

