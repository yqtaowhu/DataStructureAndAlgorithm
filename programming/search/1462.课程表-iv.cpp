/*
 * @lc app=leetcode.cn id=1462 lang=cpp
 *
 * [1462] 课程表 IV
 */

// @lc code=start
// 拓扑排序 + 可达性传递：处理节点 u 时，把所有"能到达 u 的节点"也标记为能到达 u 的后继 v。
// 用 reach[k][v] 记录 k 是否是 v 的先修课，最后 O(1) 回答每个查询。
class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites,
                                     vector<vector<int>>& queries) {
        vector<vector<int>> g(numCourses);
        vector<int> indeg(numCourses, 0);
        for (auto& p : prerequisites) { g[p[0]].push_back(p[1]); indeg[p[1]]++; }
        vector<vector<char>> reach(numCourses, vector<char>(numCourses, 0));
        queue<int> q;
        for (int i = 0; i < numCourses; i++) if (indeg[i] == 0) q.push(i);
        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (int v : g[u]) {
                reach[u][v] = 1;                       // u 是 v 的直接先修
                for (int k = 0; k < numCourses; k++)   // 传递：v 的所有先修也是 u 的先修
                    if (reach[k][u]) reach[k][v] = 1;
                if (--indeg[v] == 0) q.push(v);
            }
        }
        vector<bool> ans;
        for (auto& qr : queries) ans.push_back(reach[qr[0]][qr[1]]);
        return ans;
    }
};
// @lc code=end
