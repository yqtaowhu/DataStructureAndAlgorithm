/*
 * @lc app=leetcode.cn id=301 lang=cpp
 *
 * [301] 删除无效的括号
 */

// @lc code=start
// 求"最少删除" → BFS 按删除个数分层：每一层尝试删掉一个括号，
// 第一次出现合法串的层就是答案，收集该层全部合法串。
class Solution {
public:
    bool valid(const string& s) {
        int cnt = 0;
        for (char c : s) {
            if (c == '(') cnt++;
            else if (c == ')') { if (--cnt < 0) return false; }
        }
        return cnt == 0;
    }

    vector<string> removeInvalidParentheses(string s) {
        vector<string> ans;
        unordered_set<string> vis;
        queue<string> q;
        q.push(s); vis.insert(s);
        bool found = false;
        while (!q.empty()) {
            int sz = q.size();
            for (int i = 0; i < sz; i++) {
                string cur = q.front(); q.pop();
                if (valid(cur)) { ans.push_back(cur); found = true; }
                if (found) continue;                  // 本层已找到，不再向下扩
                for (int j = 0; j < (int)cur.size(); j++) {
                    if (cur[j] != '(' && cur[j] != ')') continue;
                    string nxt = cur.substr(0, j) + cur.substr(j + 1);
                    if (!vis.count(nxt)) { vis.insert(nxt); q.push(nxt); }
                }
            }
        }
        return ans;
    }
};
// @lc code=end
