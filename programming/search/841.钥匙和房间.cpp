/*
 * @lc app=leetcode.cn id=841 lang=cpp
 *
 * [841] 钥匙和房间
 */

// @lc code=start
// 从 0 号房间出发做 BFS/DFS，能访问到的房间数 == 总房间数即可。
class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size(), cnt = 0;
        vector<bool> vis(n, false);
        queue<int> q;
        q.push(0); vis[0] = true;
        while (!q.empty()) {
            int u = q.front(); q.pop(); cnt++;
            for (int key : rooms[u])
                if (!vis[key]) { vis[key] = true; q.push(key); }
        }
        return cnt == n;
    }
};
// @lc code=end
