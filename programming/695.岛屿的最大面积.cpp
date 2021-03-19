/*
 * @lc app=leetcode.cn id=695 lang=cpp
 *
 * [695] 岛屿的最大面积
 */

// @lc code=start
class Solution {
public:
    int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

    void dfs(vector<vector<int>>& grid, int m, int n, int i, int j, int &count) {
        if(i >=m || i < 0 || j>=n || j<0 || grid[i][j] == 0) {
            return;
        }
        count++;
        grid[i][j] = 0;
        for(int k=0; k<4; k++) {
            int tx = i + dx[k];
            int ty = j + dy[k];
            dfs(grid, m, n, tx, ty, count);
        }
        return;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if(grid.empty() || grid[0].empty()) return 0;
        int row = grid.size(), col = grid[0].size(), res = 0;
        for(int i=0; i< row; i++) {
            for(int j=0; j< col; j++) {
                if(grid[i][j] == 1) {
                    int count = 0;
                    dfs(grid, row, col, i, j, count);
                    res = max(res, count);
                }
            }
        }
        return res;
    }
};
// @lc code=end

