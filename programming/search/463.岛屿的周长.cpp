/*
 * @lc app=leetcode.cn id=463 lang=cpp
 *
 * [463] 岛屿的周长
 */

// @lc code=start
// 每个陆地格子贡献 4 条边，每有一个相邻陆地就减 1 条。
// 等价写法：只统计"越界或邻居是水"的边。
class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), ans = 0;
        int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (grid[i][j] == 1)
                    for (int d = 0; d < 4; d++) {
                        int x = i + dx[d], y = j + dy[d];
                        if (x < 0 || x >= m || y < 0 || y >= n || grid[x][y] == 0) ans++;
                    }
        return ans;
    }
};
// @lc code=end
