/*
 * @lc app=leetcode.cn id=767 lang=cpp
 *
 * [767] 重构字符串
 */

// @lc code=start
class Solution {
public:
    // 堆贪心：每次取剩余频次最高的两个不同字符交替放入，避免相邻重复。
    // 若某字符频次 > (n+1)/2，一定无法重构，直接返回空串。
    string reorganizeString(string s) {
        int cnt[26] = {0}, n = s.size();
        for (char c : s) cnt[c - 'a']++;
        // 大顶堆：{频次, 字符}
        priority_queue<pair<int, char>> pq;
        for (int i = 0; i < 26; i++) {
            if (cnt[i] > (n + 1) / 2) return "";
            if (cnt[i] > 0) pq.push({cnt[i], 'a' + i});
        }
        string res;
        while (pq.size() >= 2) {
            auto a = pq.top(); pq.pop();
            auto b = pq.top(); pq.pop();
            res += a.second; res += b.second; // 交替放两个最高频字符
            if (--a.first > 0) pq.push(a);
            if (--b.first > 0) pq.push(b);
        }
        if (!pq.empty()) res += pq.top().second; // 剩下最后一个
        return res;
    }
};
// @lc code=end
