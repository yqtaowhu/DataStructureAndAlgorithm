/*
 * @lc app=leetcode.cn id=1254 lang=cpp
 *
 * [1254] 统计封闭岛屿的数目
 */

// @lc code=start
// 封闭岛屿 = 不接触边界的陆地连通块。做法：先把所有连着边界的陆地淹掉，
// 剩下的每个陆地连通块都是封闭岛屿，计数即可。
class Solution {
public:
    void dfs(vector<vector<int>>& grid, int i, int j) {
        if (i < 0 || i >= (int)grid.size() || j < 0 || j >= (int)grid[0].size()
            || grid[i][j] == 1) return;
        grid[i][j] = 1;                              // 0(陆地) 淹成 1
        int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};
        for (int d = 0; d < 4; d++) dfs(grid, i + dx[d], j + dy[d]);
    }

    int closedIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        for (int i = 0; i < m; i++) { dfs(grid, i, 0); dfs(grid, i, n - 1); }
        for (int j = 0; j < n; j++) { dfs(grid, 0, j); dfs(grid, m - 1, j); }
        int ans = 0;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (grid[i][j] == 0) { dfs(grid, i, j); ans++; }
        return ans;
    }
};
// @lc code=end
