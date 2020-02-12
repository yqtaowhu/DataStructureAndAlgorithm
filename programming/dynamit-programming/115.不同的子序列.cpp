/*
 * @lc app=leetcode.cn id=115 lang=cpp
 *
 * [115] 不同的子序列
 */

// @lc code=start
class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.size(), m = t.size();
        if (m == 0) return 1;
        if (n == 0) return 0;
        vector<vector<long long>> dp(n + 1, vector<long long>(m + 1, 0));
        // dp[i][0] = 1, dp[0][j] = 0;
        for (int i = 0; i <= n; i++) dp[i][0] = 1;
        // 状态转移
        // s[i-1] == t[j-1]时，dp[i][j] = dp[i-1][j-1] + dp[i-1][j]  dp[i-1][j-1]表示保留s[i-1]的情况，dp[i-1][j]表示移除s[i-1]的情况
        // s[i-1] != t[j-1]时，dp[i][j] = dp[i-1][j]
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                dp[i][j] = dp[i - 1][j];
                if (s[i - 1] == t[j - 1]) dp[i][j] += dp[i - 1][j - 1];
            }
        }

        return dp[n][m];
    }
};
// @lc code=end

