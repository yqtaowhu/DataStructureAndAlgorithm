// 1456. 定长子串中元音的最大数目
// 模板：定长窗口（入 → 更新 → 出）
// 统计窗口内元音字母（aeiou）的个数，求长度为 k 的窗口中的最大值
// 技巧：抽一个 isVowel 判定，入/出各调一次，避免把五连判断写三遍

class Solution {
public:
    int maxVowels(string s, int k) {
        auto isVowel = [](char c) {
            return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
        };
        int cnt = 0, ans = 0;
        for (int right = 0; right < (int)s.size(); right++) {
            cnt += isVowel(s[right]);              // 1. 入
            if (right < k - 1) continue;           // 窗口未满
            ans = max(ans, cnt);                   // 2. 更新
            cnt -= isVowel(s[right - k + 1]);      // 3. 出
        }
        return ans;
    }
};
