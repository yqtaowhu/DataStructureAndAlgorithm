// 567. 字符串的排列
// 模板：定长窗口（入 → 更新 → 出），窗口长度 = s1.size()
// s2 中存在 s1 的排列 ⇔ 某个定长窗口的 26 字母计数与 s1 完全相等
// 与 438 唯一的区别：本题只要判断"是否存在"，命中即 return true
// 同族：438（记录所有起点）、30（按单词长度分组滑）

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s2.size(), m = s1.size();
        if (n < m) return false;
        int need[26] = {0}, window[26] = {0};
        for (char c : s1) need[c - 'a']++;
        for (int right = 0; right < n; right++) {
            window[s2[right] - 'a']++;             // 1. 入
            if (right < m - 1) continue;           // 窗口未满
            bool ok = true;                        // 2. 更新：计数相等即排列
            for (int i = 0; i < 26; i++)
                if (window[i] != need[i]) { ok = false; break; }
            if (ok) return true;                   // 命中即返回
            window[s2[right - m + 1] - 'a']--;     // 3. 出
        }
        return false;
    }
};
