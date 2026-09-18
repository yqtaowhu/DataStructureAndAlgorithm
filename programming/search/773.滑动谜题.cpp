/*
 * @lc app=leetcode.cn id=773 lang=cpp
 *
 * [773] 滑动谜题
 */

// @lc code=start
// 状态空间 BFS：把 2x3 棋盘压成长度 6 的字符串，0 每次与相邻位交换。
// 预存每个下标可交换的邻居，从初始状态搜到 "123450"，层数即最少步数。
class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        string start;
        for (auto& row : board) for (int x : row) start += to_string(x);
        const string target = "123450";
        // 一维下标 i 的相邻可交换位置
        vector<vector<int>> nxt = {{1,3},{0,2,4},{1,5},{0,4},{1,3,5},{2,4}};
        unordered_set<string> vis;
        queue<string> q;
        q.push(start); vis.insert(start);
        int step = 0;
        while (!q.empty()) {
            int sz = q.size();
            for (int i = 0; i < sz; i++) {
                string cur = q.front(); q.pop();
                if (cur == target) return step;
                int pos = cur.find('0');
                for (int p : nxt[pos]) {
                    string s = cur; swap(s[pos], s[p]);
                    if (vis.count(s)) continue;
                    vis.insert(s); q.push(s);
                }
            }
            step++;
        }
        return -1;
    }
};
// @lc code=end
