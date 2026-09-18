/*
 * @lc app=leetcode.cn id=526 lang=cpp
 *
 * [526] 优美的排列
 *
 * 状态压缩 DP（计数型）。用一个二进制数 mask 表示"哪些数字已经被放置"，
 * mask 的第 j 位为 1 表示数字 j+1 已用。已放置的个数 = popcount(mask)，
 * 因此下一个要填的位置就是 pos = popcount(mask) + 1。
 * dp[mask] = 得到该放置状态的方案数。
 */

// @lc code=start
class Solution {
public:
    int countArrangement(int n) {
        vector<int> dp(1 << n, 0);
        dp[0] = 1; // 空状态：一种方案
        for (int mask = 0; mask < (1 << n); ++mask) {
            int pos = __builtin_popcount(mask) + 1; // 当前要填的位置
            if (pos > n) continue;
            for (int j = 0; j < n; ++j) {
                if (mask & (1 << j)) continue; // 数字 j+1 已被使用
                int num = j + 1;
                // 优美排列条件：num 与 pos 互为整除
                if (num % pos == 0 || pos % num == 0) {
                    dp[mask | (1 << j)] += dp[mask];
                }
            }
        }
        return dp[(1 << n) - 1];
    }
};
// @lc code=end
