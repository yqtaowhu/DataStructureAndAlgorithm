/*
 * @lc app=leetcode.cn id=200 lang=cpp
 *
 * [200] 岛屿数量
 */

// @lc code=start
class Solution {
public:
    int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
    void dfs(vector<vector<char>>& grid, int r, int c, int i, int j) {
        if(i < 0 || i >= r || j < 0 || j >= c || grid[i][j] == '0')
            return;
        grid[i][j] = '0';
        for(int k=0; k<4; k++) {
            int r_t = i + dx[k];
            int c_t = j + dy[k];
            dfs(grid, r, c, r_t, c_t);
        }
        
    }

    int numIslands(vector<vector<char>>& grid) {
        if(grid.empty() || grid[0].empty()) return 0;
        int m = grid.size(), n = grid[0].size();
        int res = 0;
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j] == '1') {
                    res++;
                    dfs(grid, m, n, i, j);
                }
            }
        }
        return res;
    }
};
// @lc code=end

