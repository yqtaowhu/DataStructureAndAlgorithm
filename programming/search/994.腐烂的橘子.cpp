/*
 * @lc app=leetcode.cn id=994 lang=cpp
 *
 * [994] 腐烂的橘子
 */

// @lc code=start
class Solution {
public:
    // bfs : 1. 先将所有腐烂橘子加入队列，为第一层, 同时统计新橘子的数量count
    // 将所以第一层出队，同时进行入队的操作，每次入队，说明有新橘子被腐烂，所以新橘子count--
    // 根据count进行判断，输出答案
    int orangesRotting(vector<vector<int>>& grid) {
        if(grid.empty() || grid[0].empty()) return -1;
        int m = grid.size(), n = grid[0].size();
        queue<pair<int, int> > que;
        int count = 0, res = 0;
        // 初始化操作
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j] == 2) {
                    que.push({i,j});
                }
                if(grid[i][j] == 1) {
                    count++;
                }
            }
        }
        int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1}; 
        while(count && !que.empty()) {
            res++;
            int num = que.size(); // 当前层的个数
            for(int i=0; i<num; i++) {
                int r = que.front().first;
                int c = que.front().second;
                que.pop();
                // 四个方向进行遍历
                for(int i=0; i<4; i++) {
                    int r_tmp = r + dx[i];
                    int c_tmp = c + dy[i];
                    if(r_tmp >=0 && r_tmp<m && c_tmp >=0 && c_tmp<n && grid[r_tmp][c_tmp] == 1) {
                        grid[r_tmp][c_tmp] = 2;
                        que.push({r_tmp, c_tmp});
                        count--;
                    }
                }
            }
        }
        return count ? -1: res;
    }
};
// @lc code=end

