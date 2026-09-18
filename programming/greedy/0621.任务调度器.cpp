/*
 * @lc app=leetcode.cn id=621 lang=cpp
 *
 * [621] 任务调度器
 */

// @lc code=start
class Solution {
public:
    // 贪心公式法：设出现次数最多的任务次数为 maxCnt，并列最多的任务有 k 个。
    // 以 maxCnt 任务搭骨架，形成 (maxCnt-1) 个长度为 (n+1) 的间隔槽，末尾再放 k 个。
    // 当任务种类多到能填满所有冷却空隙时，直接取任务总数即可。
    int leastInterval(vector<char>& tasks, int n) {
        int cnt[26] = {0};
        for (char c : tasks) cnt[c - 'A']++;
        int maxCnt = 0;
        for (int i = 0; i < 26; i++) maxCnt = max(maxCnt, cnt[i]);
        int ties = 0; // 与 maxCnt 并列的任务种类数
        for (int i = 0; i < 26; i++) if (cnt[i] == maxCnt) ties++;
        int slots = (maxCnt - 1) * (n + 1) + ties;
        return max((int)tasks.size(), slots);
    }
};
// @lc code=end
