/*
 * @lc app=leetcode.cn id=785 lang=cpp
 *
 * [785] 判断二分图
 */

// @lc code=start
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
// @lc code=end

