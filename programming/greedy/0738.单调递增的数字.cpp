/*
 * @lc app=leetcode.cn id=738 lang=cpp
 *
 * [738] 单调递增的数字
 */

// @lc code=start
class Solution {
public:
    // 贪心：从高位向低位找第一个「下降位」i（digits[i] > digits[i+1]）。
    // 让 digits[i] 减 1，并把 i 之后全部置 9，即得 <= n 的最大递增数。
    // 减 1 后可能破坏前面的递增（如 332 -> 322），需从后往前回退处理。
    int monotoneIncreasingDigits(int n) {
        string s = to_string(n);
        int len = s.size(), mark = len; // mark：从此位开始全填 9
        for (int i = len - 1; i > 0; i--) {
            if (s[i - 1] > s[i]) {
                s[i - 1]--;    // 前一位减 1
                mark = i;      // 该位及其后全部变 9
            }
        }
        for (int i = mark; i < len; i++) s[i] = '9';
        return stoi(s);
    }
};
// @lc code=end
