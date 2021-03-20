
# 搜索相关算法
搜索一般是dfs, bfs，两者都有一定的模板

## 1. [岛屿数量](https://leetcode-cn.com/problems/number-of-islands/)

经典dfs的模板如下: 
```
class Solution {
public:
    int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
    void dfs(vector<vector<char>>& grid, int r, int c, int rows, int cols) {
        // 经典的退出条件
        if(r < 0 || c < 0 || r >= rows || c >= cols || grid[r][c] == '0') {
            return;
        }
        grid[r][c] = '0';
        for(int k=0; k<4; k++) {
            int rx = r + dx[k];
            int ry = c + dy[k];
            dfs(grid, rx, ry, rows, cols);
        }
        return;
    }
    int numIslands(vector<vector<char>>& grid) {
        // 深度优先搜索
        if(grid.empty() || grid[0].empty()) return 0;
        int rows = grid.size(), cols = grid[0].size();
        int total = 0;
        for(int i=0; i < rows; ++i) {
            for(int j=0; j < cols; ++j) {
                if(grid[i][j] == '1') {
                    total += 1;
                    // 遍历所有的岛屿
                    dfs(grid, i, j, rows, cols);
                }
            }
        }
        return total;
    }
};
```

经典bfs如下:

```
class Solution {
public:  
    int numIslands(vector<vector<char>>& grid) {
        // 深度优先搜索
        if(grid.empty() || grid[0].empty()) return 0;
        int rows = grid.size(), cols = grid[0].size();
        int total = 0, dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
        for(int i=0; i < rows; ++i) {
            for(int j=0; j < cols; ++j) {
                if(grid[i][j] == '1') {
                    total += 1;
                    // 遍历所有的岛屿
                    queue<pair<int, int>> que;       
                    grid[i][j] = '0';
                    que.push({i, j});
                    while(!que.empty()) {
                        int x = que.front().first;
                        int y = que.front().second;
                        que.pop();
                        // 遍历四周
                        for(int k = 0; k < 4; k++) {
                            // 满足条件的加入队列中
                            int tx = x + dx[k];
                            int ty = y + dy[k];
                            // 经典的条件
                            if(tx >= 0 && ty >= 0 && tx < rows && ty < cols && grid[tx][ty] == '1') {
                                que.push({tx, ty});
                                // ------------ 加入就改变状态， 切记------------------
                                grid[tx][ty] = '0';
                            }
                        }
                    }
                }
            }
        }
        return total;
    }
};
```