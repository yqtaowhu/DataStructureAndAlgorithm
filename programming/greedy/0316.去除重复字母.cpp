/*
 * @lc app=leetcode.cn id=316 lang=cpp
 *
 * [316] 去除重复字母（等价 1081 不同字符的最小子序列）
 */

// @lc code=start
class Solution {
public:
    // 单调栈贪心：结果需满足 ①每个字母只出现一次 ②字典序最小 ③保持相对顺序。
    // 与 402 的区别：删栈顶前必须确认「该字母后面还会出现」，否则删了就丢了。
    string removeDuplicateLetters(string s) {
        int last[26] = {0};          // 每个字母最后一次出现的下标
        bool inStack[26] = {false};  // 字母是否已在栈中
        for (int i = 0; i < (int)s.size(); i++) last[s[i] - 'a'] = i;

        string stk;
        for (int i = 0; i < (int)s.size(); i++) {
            char c = s[i];
            if (inStack[c - 'a']) continue; // 已存在，跳过保证唯一
            // 栈顶比当前大，且栈顶字母后面还会出现 -> 可以安全弹出
            while (!stk.empty() && stk.back() > c && last[stk.back() - 'a'] > i) {
                inStack[stk.back() - 'a'] = false;
                stk.pop_back();
            }
            stk.push_back(c);
            inStack[c - 'a'] = true;
        }
        return stk;
    }
};
// @lc code=end
