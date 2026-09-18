/*
 * @lc app=leetcode.cn id=542 lang=cpp
 *
 * [542] 01 矩阵
 */

// @lc code=start
// 多源 BFS：把所有 0 一次性入队作为超级源点，向外一层层扩散，
// 层数即为到最近 0 的距离。
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> dist(m, vector<int>(n, -1));
        queue<pair<int, int>> q;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (mat[i][j] == 0) { dist[i][j] = 0; q.push({i, j}); }
        int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};
        while (!q.empty()) {
            auto [x, y] = q.front(); q.pop();
            for (int d = 0; d < 4; d++) {
                int nx = x + dx[d], ny = y + dy[d];
                if (nx < 0 || nx >= m || ny < 0 || ny >= n || dist[nx][ny] != -1) continue;
                dist[nx][ny] = dist[x][y] + 1;   // 入队时即确定最短距离
                q.push({nx, ny});
            }
        }
        return dist;
    }
};
// @lc code=end
