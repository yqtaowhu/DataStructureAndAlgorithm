/*
 * @lc app=leetcode.cn id=886 lang=cpp
 *
 * [886] 可能的二分法
 */

// @lc code=start
// 与 785 判断二分图完全同款：把"互相不喜欢"看成无向边，
// 能否把人分成两组 = 图能否二染色。
class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> g(n + 1);
        for (auto& e : dislikes) { g[e[0]].push_back(e[1]); g[e[1]].push_back(e[0]); }
        vector<int> color(n + 1, 0);                  // 0 未染色，1/-1 两色
        for (int i = 1; i <= n; i++) {
            if (color[i]) continue;                   // 已染色则跳过
            queue<int> q; q.push(i); color[i] = 1;
            while (!q.empty()) {
                int u = q.front(); q.pop();
                for (int v : g[u]) {
                    if (!color[v]) { color[v] = -color[u]; q.push(v); }
                    else if (color[v] == color[u]) return false;   // 相邻同色 → 冲突
                }
            }
        }
        return true;
    }
};
// @lc code=end
