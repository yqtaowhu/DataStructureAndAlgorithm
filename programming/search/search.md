- [搜索相关算法](#搜索相关算法)
  - [1. 岛屿数量](#1-岛屿数量)
  - [2. 岛屿的最大面积](#2-岛屿的最大面积)
  - [3.  被围绕的区域](#3--被围绕的区域)
  - [4. 判断二分图](#4-判断二分图)
  - [5.拓扑排序](#5拓扑排序)
    - [5.1 判断是否有环](#51-判断是否有环)
    - [5.2 判断是否有环](#52-判断是否有环)
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

## 2. [岛屿的最大面积](https://leetcode-cn.com/problems/max-area-of-island/)
和上一题基本完全一样，只不过加一个变量记录个数
```
class Solution {
public:
    // 同样可以bfs,dfs
    int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
    void dfs(vector<vector<int>>& grid, int r, int c, int rows, int cols, int& res) {
        // 经典的退出条件
        if(r < 0 || c < 0 || r >= rows || c >= cols || grid[r][c] == 0) {
            return;
        }
        grid[r][c] = 0;
        res += 1;
        for(int k=0; k<4; k++) {
            int rx = r + dx[k];
            int ry = c + dy[k];
            dfs(grid, rx, ry, rows, cols, res);
        }
        return;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        // 深度优先搜索
        if(grid.empty() || grid[0].empty()) return 0;
        int rows = grid.size(), cols = grid[0].size();
        int total = 0;
        for(int i=0; i < rows; ++i) {
            for(int j=0; j < cols; ++j) {
                if(grid[i][j] == 1) {
                    int res = 0;
                    // 遍历所有的岛屿
                    dfs(grid, i, j, rows, cols, res);
                    total = max(total, res);
                }
            }
        }
        return total;
    }
};
```

## 3. [ 被围绕的区域](https://leetcode-cn.com/problems/surrounded-regions/)

// 逆向思维，从边界处，遍历O，将相邻的O置为true
// 将false置为X

dfs的方法
```
class Solution {
public:
    // 逆向思维，从边界处，遍历O，将相邻的O置为true
    // 将false置为X

    int m, n;
    void solve(vector<vector<char>>& board) {
        if(board.empty()) return;
        m=board.size();
        n=board[0].size();
        vector<vector<int> > visit(m, vector<int>(n,0));
        // 行
        for(int i=0; i<n; i++) {
            if(board[0][i] == 'O') dfs(0, i, board, visit);
            if(board[m-1][i] == 'O') dfs(m-1, i, board, visit);   
        }
        // 列
        for(int i=0; i<m; i++) {
            if(board[i][0] == 'O') dfs(i, 0, board, visit);
            if(board[i][n-1] == 'O') dfs(i, n-1, board, visit);
        }
        // 填充
        for (int i = 0; i < m; i ++ )
            for (int j = 0; j < n; j ++ )
                if (!visit[i][j])
                    board[i][j] = 'X';
    }
    
    void dfs(int x, int y, vector<vector<char> > &board, vector<vector<int> > &visit) {
        visit[x][y] = 1;
        int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
        for(int i=0; i<4; i++) {
            int a = x+dx[i], b = y+dy[i];
            if(a>=0 && a<m && b>=0 && b<n && !visit[a][b] && board[a][b] == 'O') {
                dfs(a, b, board, visit);
            }
        }
    }
};
```
bfs: bfs的方法写着更舒畅
```
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if(board.empty() || board[0].empty()) {
            return;
        }
        int rows = board.size(), cols = board[0].size();
        queue<pair<int, int>> que;
        vector<vector<int>> vis(rows, vector<int>(cols, 0));
        // 将所有的边界0加入队列中
        for(int i=0; i<rows; ++i) {
            for(int j=0; j<cols; ++j) {
                if((board[i][j] == 'O') && (i==0 || j==0 || i==rows-1 || j==cols-1)) {
                    que.push({i, j});
                    vis[i][j] = 1;
                }
            }
        }
        int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
        while(!que.empty()) {
            int x = que.front().first;
            int y = que.front().second;
            que.pop();
            for(int k=0; k<4; k++) {
                int rx = x + dx[k];
                int ry = y + dy[k];
                if(rx >=0 && ry >= 0 && rx < rows && ry < cols && 
                    vis[rx][ry] == 0 && board[rx][ry] == 'O') {
                        que.push({rx, ry});
                        vis[rx][ry] = 1;
                    }
            }
        }
        for(int i=0; i< rows; i++) {
            for(int j=0; j<cols; j++) {
                if(!vis[i][j]) {
                    board[i][j] = 'X';
                }
            }
        }
    }
};
```

## 4. [判断二分图](https://leetcode-cn.com/problems/is-graph-bipartite/)

标准的bfs算法，将周边的节点颜色标注相反的颜色，如果已经标注且颜色相同，则不为二分图。


```
class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        if(graph.empty()) {
            return true;
        }
        int n = graph.size();
        vector<int> color(n, 0);  // 初始化不染色
        queue<int> que;
        for(int i=0; i<n; i++) {
            if(color[i] == 0) {
                que.push(i);
                color[i] = 1;     // 开始染色，给1
            }
            while(!que.empty()) {
                int x = que.front();
                que.pop();
                for(auto &y:graph[x]) {
                    if(color[y] == 0) {
                        que.push(y);
                        color[y] = color[x] == 1 ? 2 : 1;   // 给和x相反的颜色
                    } else {
                        if(color[x] == color[y]) {
                            return false;
                        }
                    }
                }
            }
        }
        return true;
    }
};
```

## 5.拓扑排序
### 5.1 [判断是否有环](https://leetcode-cn.com/problems/course-schedule/)
```
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // 拓扑排序问题，构建邻接矩阵和入度标
        if(prerequisites.empty()) {
            return true;
        }
        vector<vector<int>> graph(numCourses, vector<int>());
        vector<int> indegree(numCourses, 0);
        int total = 0;
        for(auto &pre : prerequisites) {
            graph[pre[1]].push_back(pre[0]);   // 1->0
            indegree[pre[0]]++;
        }
        queue<int> que;
        // 入度为0的表加入队列中，入度为0说明其没有学习的条件
        for(int i=0; i < numCourses; i++) {
            if(indegree[i] == 0) {
                que.push(i);
            }
        }
        while(!que.empty()) {
            int node = que.front();
            que.pop();
            total++;
            for(auto &adj : graph[node]) {
                indegree[adj]--;      // 邻接节点入度减1
                if(indegree[adj] == 0) {
                    que.push(adj);
                }
            }
        }
        return total == numCourses;
    }
};
```
### 5.2 [判断是否有环](https://leetcode-cn.com/problems/course-schedule-ii/)

给出拓扑排序的结果，和上一题基本一样

```
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
          // 拓扑排序问题，构建邻接矩阵和入度标
        vector<vector<int>> graph(numCourses, vector<int>());
        vector<int> indegree(numCourses, 0), res;
        for(auto &pre : prerequisites) {
            graph[pre[1]].push_back(pre[0]);   // 1->0
            indegree[pre[0]]++;
        }
        queue<int> que;
        // 入度为0的表加入队列中，入度为0说明其没有学习的条件
        for(int i=0; i < numCourses; i++) {
            if(indegree[i] == 0) {
                que.push(i);
            }
        }
        while(!que.empty()) {
            int node = que.front();
            que.pop();
            res.push_back(node);
            for(auto &adj : graph[node]) {
                indegree[adj]--;      // 邻接节点入度减1
                if(indegree[adj] == 0) {
                    que.push(adj);
                }
           }
        }
        // 最后的入度全为0
        for(int i=0; i < indegree.size(); i++) {
            if(indegree[i]) {
                return vector<int>();
            }
        }
        return res;
    }
};
```

