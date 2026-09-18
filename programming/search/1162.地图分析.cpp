/*
 * @lc app=leetcode.cn id=1162 lang=cpp
 *
 * [1162] 地图分析
 */

// @lc code=start
class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        const int M = grid.size();
        const int N = grid[0].size();
        // 使用deque作为队列
        deque<pair<int, int>> deq;
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                if (grid[i][j] == 1) {
                    // 将所有陆地都放入队列中
                    deq.push_back({i, j});
                }
            }
        }
        // 如果没有陆地或者海洋，返回-1
        if (deq.size() == 0 || deq.size() == M * N) {
            return -1;
        }
        // 由于BFS的第一层遍历是从陆地开始，因此遍历完第一层之后distance应该是0
        int distance = -1;
        // 对队列的元素进行遍历
        while (deq.size() != 0) {
            // 新遍历了一层
            distance ++;
            // 当前层的元素有多少，在该轮中一次性遍历完当前层
            int size = deq.size();
            while (size --) {
                // BFS遍历的当前元素永远是队列的开头元素
                auto cur = deq.front(); deq.pop_front();
                // 对当前元素的各个方向进行搜索
                for (auto& d : directions) {
                    int x = cur.first + d[0];
                    int y = cur.second + d[1];
                    // 如果搜索到的新坐标超出范围/陆地/已经遍历过，则不搜索了
                    if (x < 0 || x >= M || y < 0 || y >= N ||
                        grid[x][y] != 0) {
                        continue;
                    }
                    // 把grid中搜索过的元素设置为2
                    grid[x][y] = 2;
                    // 放入队列中
                    deq.push_back({x, y});
                }
            }
        }
        // 最终走了多少层才把海洋遍历完
        return distance;
    }
private:
    vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
};
// @lc code=end

