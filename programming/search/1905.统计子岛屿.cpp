/*
 * @lc app=leetcode.cn id=1905 lang=cpp
 *
 * [1905] 统计子岛屿
 */

// @lc code=start
// 遍历 grid2 的每个岛屿，DFS 过程中逐格检查 grid1 对应位置是否也是陆地。
// 只有整块都落在 grid1 的陆地上才算子岛屿（用 & 累积，不能提前 return）。
class Solution {
public:
    bool dfs(vector<vector<int>>& g1, vector<vector<int>>& g2, int i, int j) {
        if (i < 0 || i >= (int)g2.size() || j < 0 || j >= (int)g2[0].size()
            || g2[i][j] == 0) return true;           // 水域不影响判定
        g2[i][j] = 0;                                 // 标记已访问
        bool res = (g1[i][j] == 1);                   // 当前格必须是陆地
        int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};
        for (int d = 0; d < 4; d++)
            res &= dfs(g1, g2, i + dx[d], j + dy[d]); // 必须走完，不能短路返回
        return res;
    }

    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int m = grid2.size(), n = grid2[0].size(), ans = 0;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (grid2[i][j] == 1 && dfs(grid1, grid2, i, j)) ans++;
        return ans;
    }
};
// @lc code=end
