// 1371. 每个元音包含偶数次的最长子字符串
// https://leetcode.cn/problems/find-the-longest-substring-containing-vowels-in-even-counts/
//
// 【前缀和 + 哈希表 · 模式二：最长型 + 状态压缩】
// 见模板文档：./前缀和哈希表模板.md
//
// 题意：找最长子串，使其中 a/e/i/o/u 每个元音都出现「偶数次」。
//
// 关键转化：把「5 个元音各自出现次数的奇偶」压成一个 5 位二进制数 state
//          （第 b 位为 1 表示对应元音出现了奇数次）。
//          某段子串每个元音都是偶数次 <=> 这段首尾的 state 完全相同（异或为 0）。
// 于是问题等价于「相同 state 之间的最大距离」，与 525 完全同构：
//          哈希表存每个 state 首次出现的下标，再次遇到就更新答案。
//
// 这就是把「前缀和」推广成「前缀异或/前缀状态」的典型：加法换成异或即可。

class Solution {
public:
    int findTheLongestSubstring(string s) {
        vector<int> first(1 << 5, -2); // 32 种奇偶状态 -> 首次下标；-2 表示未出现过
        first[0] = -1;                 // 空状态（全偶数）从下标 -1 开始
        int state = 0, ans = 0;
        for (int i = 0; i < (int)s.size(); i++) {
            switch (s[i]) {            // 遇到元音就翻转对应位（异或）
                case 'a': state ^= 1;  break;
                case 'e': state ^= 2;  break;
                case 'i': state ^= 4;  break;
                case 'o': state ^= 8;  break;
                case 'u': state ^= 16; break;
            }
            if (first[state] != -2) {
                ans = max(ans, i - first[state]); // 相同状态 => 中间段全为偶数次
            } else {
                first[state] = i;                 // 只存最早下标，才能保证最长
            }
        }
        return ans;
    }
};
