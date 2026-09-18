/*
 * @lc app=leetcode.cn id=310 lang=cpp
 *
 * [310] 最小高度树
 */

// @lc code=start
// 拓扑"剥叶子"：每轮删掉当前所有度为 1 的叶子，剩下的最后一层（1 或 2 个）
// 就是能使树高最小的根。等价于找树的"重心/直径中点"。
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1) return {0};
        vector<vector<int>> g(n);
        vector<int> deg(n, 0);
        for (auto& e : edges) {
            g[e[0]].push_back(e[1]); g[e[1]].push_back(e[0]);
            deg[e[0]]++; deg[e[1]]++;
        }
        queue<int> q;
        for (int i = 0; i < n; i++) if (deg[i] == 1) q.push(i);   // 初始叶子
        int remain = n;
        while (remain > 2) {                            // 剩到 1 或 2 个即为答案
            int sz = q.size(); remain -= sz;
            for (int i = 0; i < sz; i++) {
                int u = q.front(); q.pop();
                for (int v : g[u]) if (--deg[v] == 1) q.push(v);
            }
        }
        vector<int> ans;
        while (!q.empty()) { ans.push_back(q.front()); q.pop(); }
        return ans;
    }
};
// @lc code=end
