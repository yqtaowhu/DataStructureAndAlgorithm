/*
 * @lc app=leetcode.cn id=1143 lang=cpp
 *
 * [1143] 最长公共子序列
 *
 * 模板三：双序列 DP。dp[i][j] = s 前 i 个与 t 前 j 个的 LCS 长度。
 * 相等斜着继承 +1，不等丢一个（取 max）。
 */

// @lc code=start
class Solution {
public:
    // 写法一：标准二维 DP（最好理解，直接对应模板）
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size(), n = text2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (text1[i - 1] == text2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;      // 匹配：斜着继承
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]); // 不匹配：丢一个
                }
            }
        }
        return dp[m][n];
    }

    // 写法二：滚动数组优化，空间 O(n)
    // dp[i][j] 只依赖上一行，用一维数组 + pre 保存左上角 dp[i-1][j-1]
    int longestCommonSubsequence_roll(string text1, string text2) {
        int m = text1.size(), n = text2.size();
        vector<int> dp(n + 1, 0);
        for (int i = 1; i <= m; i++) {
            int pre = 0; // pre 记录 dp[i-1][j-1]
            for (int j = 1; j <= n; j++) {
                int tmp = dp[j]; // 保存覆盖前的 dp[i-1][j]，供下一轮当 pre
                if (text1[i - 1] == text2[j - 1]) {
                    dp[j] = pre + 1;
                } else {
                    dp[j] = max(dp[j], dp[j - 1]);
                }
                pre = tmp;
            }
        }
        return dp[n];
    }
};
// @lc code=end
