// 76. 最小覆盖子串
// 模板二：不定长窗口 · 求最短（覆盖型三件套 need + window + valid）
// 口诀：求最短 ⇒ 边出边更新，答案在 while 收缩的过程中记录
// 同族：438 / 567（定长版）、30（按单词定长）、3697 / 3698（覆盖型计数）

/*
(滑动窗口 · 覆盖型求最短) O(n + m)

1.预处理：need[c] 记 t 中字符 c 的需求量，kinds 记 t 中不同字符的种类数
2.right 入窗：window[c]++；仅当 window[c] == need[c]（刚好凑够）时 valid++，
  这样同一字符超量也不会重复计数，valid 的含义始终是"已凑够的字符种类数"
3.收缩条件：valid == kinds，即窗口已覆盖 t 的全部字符
4.求最短 ⇒ 在 while 内先用 [left, right] 更新答案，再移出左端字符 d：
  移出前若 window[d] == need[d]，说明 d 即将不够，valid--（判断和自增都统一写 ==）
5.窗口不再覆盖后回到第 2 步继续扩张，直到 right 走完 s

计数容器用 int[128] 代替 unordered_map<char,int>（字符集为 ASCII）：
省掉哈希开销，need/window 空间降为 O(1)。
下标写 (unsigned char)s[i] 是因为 macOS/clang 下 char 默认有符号，直接当下标会触发
-Wchar-subscripts 告警且脏数据可能负值越界。

复杂度分析：left、right 各最多前进 n 次，数组读写 O(1)，总时间 O(n + m)，空间 O(1)。
*/

// @lc code=start
class Solution {
public:
    // 滑动窗口模板题（计数数组版，不用 hash）
    string minWindow(string s, string t) {
        int need[128] = {0}, window[128] = {0};
        int kinds = 0;                                   // t 中不同字符的种类数
        for (char c : t) {
            if (need[(unsigned char)c]++ == 0) kinds++;
        }
        int left = 0, valid = 0;                         // valid：已凑够的种类数
        int start = 0, minLen = INT_MAX;
        for (int right = 0; right < (int)s.size(); right++) {
            unsigned char c = s[right];
            window[c]++;                                 // 入
            if (need[c] > 0 && window[c] == need[c]) valid++;
            while (valid == kinds) {                     // 出：已覆盖 t，开始收缩
                if (right - left + 1 < minLen) {         // 收缩前更新：此窗口合法
                    minLen = right - left + 1;
                    start = left;
                }
                unsigned char d = s[left++];
                if (need[d] > 0 && window[d] == need[d]) valid--;   // d 马上不够了
                window[d]--;
            }
        }
        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
};
// @lc code=end

/*
通用哈希版：字符集未知（或元素不是 char，如数字、字符串）时用 unordered_map，
骨架与上面完全一致，只是把 need/window 换成哈希表、kinds 换成 need.size()。
438 / 567 / 30 都是这一套的变体，可以直接改收缩条件复用。
*/
class SolutionHash {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> need, window;
        for (char c : t) need[c]++;
        int left = 0, valid = 0, start = 0, minLen = INT_MAX;
        for (int right = 0; right < (int)s.size(); right++) {
            char c = s[right];
            if (need.count(c)) {                         // 入：只统计 t 中出现的字符
                window[c]++;
                if (window[c] == need[c]) valid++;
            }
            while (valid == (int)need.size()) {           // 出：种类全部凑够
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    start = left;
                }
                char d = s[left++];
                if (need.count(d)) {
                    if (window[d] == need[d]) valid--;
                    window[d]--;
                }
            }
        }
        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
};

/* ==================== 以下为原有解法（保留，逻辑未改动，仅类名改名避免重定义） ==================== */
// 滑动窗口，收缩的条件要明确

class SolutionOrigin {
public:
string minWindow(string s, string t) {
    unordered_map<char, int> need, hash;
    int s_size = s.size(), t_size = t.size();
    int need_cnt = 0, match = 0;
    for(int i=0; i < t_size; i++) {
        need[t[i]]++;
    }
    int beg = 0, end = 0, min_len=INT_MAX;
    int start = 0;
    while(end < s_size) {
        char c = s[end];
        if(need.count(c)) {
            hash[c]++;
            if (need[c] == hash[c]) {
                match++;
            }
        }
        end++;
        // 满足条件后，才进行窗口的减少
        while (match == need.size()) {
            if(end-beg < min_len) {
                start = beg;
                min_len = end-beg;
            }
            char c2 = s[beg];
            if(need.count(c2)) {
                // 这里注意条件, 都统一写成==
                if(hash[c2] == need[c2]) {
                    match--;
                }
                hash[c2]--;
            }
            beg++;
        }
    }
    return  min_len == INT_MAX ? "" : s.substr(start, min_len);
}
};