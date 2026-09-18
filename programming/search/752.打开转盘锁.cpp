/*
 * @lc app=leetcode.cn id=752 lang=cpp
 *
 * [752] 打开转盘锁
 */

// @lc code=start
// 状态空间 BFS：每个"0000"~"9999"是一个节点，每次拨一位有 8 个后继。
// 从 "0000" 出发按层扩展，第一次到达 target 的层数即最少旋转次数。
class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> dead(deadends.begin(), deadends.end());
        if (dead.count("0000")) return -1;
        if (target == "0000") return 0;
        unordered_set<string> vis;
        queue<string> q;
        q.push("0000"); vis.insert("0000");
        int step = 0;
        while (!q.empty()) {
            int sz = q.size(); step++;
            for (int i = 0; i < sz; i++) {
                string cur = q.front(); q.pop();
                for (int j = 0; j < 4; j++)
                    for (int d : {-1, 1}) {
                        string nxt = cur;
                        nxt[j] = (nxt[j] - '0' + d + 10) % 10 + '0';
                        if (dead.count(nxt) || vis.count(nxt)) continue;
                        if (nxt == target) return step;
                        vis.insert(nxt); q.push(nxt);
                    }
            }
        }
        return -1;
    }
};
// @lc code=end
