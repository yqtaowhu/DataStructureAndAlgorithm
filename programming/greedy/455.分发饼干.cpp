/*
 * @lc app=leetcode.cn id=455 lang=cpp
 *
 * [455] 分发饼干
 */

// @lc code=start
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        if (s.empty() || g.empty()) {
            return 0;
        }
        // 贪心，让小饼干给胃口小的孩子，先满足胃口小的孩子
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int res = 0, child = 0, candy = 0;
        while(child < g.size() && candy < s.size()) {
            // 满足和不满足条件饼干都要++
            if(g[child] <= s[candy]) {
                res++;
                child++;
            }
            candy++;
        }
        return res;
    }
};
// @lc code=end

