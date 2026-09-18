/*
 * @lc app=leetcode.cn id=1020 lang=cpp
 *
 * [1020] 飞地的数量
 */

// @lc code=start
// 与 130/1254 同款逆向思维：先把所有能走到边界的陆地淹掉，
// 剩下的陆地就是"飞地"，直接计数即可。
class Solution {
public:
    void dfs(vector<vector<int>>& grid, int i, int j) {
        if (i < 0 || i >= (int)grid.size() || j < 0 || j >= (int)grid[0].size()
            || grid[i][j] == 0) return;
        grid[i][j] = 0;
        int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};
        for (int d = 0; d < 4; d++) dfs(grid, i + dx[d], j + dy[d]);
    }

    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        for (int i = 0; i < m; i++) { dfs(grid, i, 0); dfs(grid, i, n - 1); }
        for (int j = 0; j < n; j++) { dfs(grid, 0, j); dfs(grid, m - 1, j); }
        int ans = 0;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (grid[i][j] == 1) ans++;
        return ans;
    }
};
// @lc code=end
