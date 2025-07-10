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

class Solution {
public:

    int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
    int numIslands(vector<vector<char>>& grid) {
        // bfs  
        if(grid.empty() || grid[0].empty()) {
            return 0;
        }
        int res = 0, m = grid.size(), n = grid[0].size();
        queue<pair<int, int>> que;
        for(int i=0; i < m; i++) {
            for(int j=0; j< n; j++) {
                if(grid[i][j] == '1') {
                    res++;
                    que.push({i, j});
                    while(!que.empty()) {
                        auto t = que.front();
                        que.pop();
                        int x = t.first, y = t.second;
                        grid[x][y] = '0';
                        for(int k=0; k < 4; k++) {
                            int r_x = x + dx[k];
                            int c_y = y + dy[k];
                            if(r_x < 0 || r_x >= m || c_y < 0 || c_y >= n || 
                                grid[r_x][c_y] == '0') {
                                continue;
                            }
                            // 入队是标记！！！！！！！！！！
                            grid[r_x][c_y] = '0';
                            que.push({r_x, c_y});
                        }
                    }
                }
            }
        }
        return res;
    }
};