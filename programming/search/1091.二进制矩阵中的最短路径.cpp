/*
 * @lc app=leetcode.cn id=1091 lang=cpp
 *
 * [1091] 二进制矩阵中的最短路径
 */

// @lc code=start
// 求最短路径长度 → BFS（层数即步数）。区别只是八个方向。
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[0][0] == 1) return -1;               // 起点被堵
        if (n == 1) return 1;
        int dx[8] = {-1,-1,-1,0,0,1,1,1}, dy[8] = {-1,0,1,-1,1,-1,0,1};
        vector<vector<int>> dist(n, vector<int>(n, -1));
        queue<pair<int, int>> q;
        q.push({0, 0}); dist[0][0] = 1;               // 长度含起点，初始为 1
        while (!q.empty()) {
            auto [x, y] = q.front(); q.pop();
            for (int d = 0; d < 8; d++) {
                int nx = x + dx[d], ny = y + dy[d];
                if (nx < 0 || nx >= n || ny < 0 || ny >= n
                    || grid[nx][ny] == 1 || dist[nx][ny] != -1) continue;
                dist[nx][ny] = dist[x][y] + 1;
                if (nx == n - 1 && ny == n - 1) return dist[nx][ny];
                q.push({nx, ny});
            }
        }
        return -1;
    }
};
// @lc code=end
