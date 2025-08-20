class Solution {
public:
    // // dp[i][j] s[:i],t[:j]的最长公共子序列
    // int longestCommonSubsequence(string text1, string text2) {
    //     int m = text1.size(), n = text2.size();
    //     vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
    //     for(int i = 1; i <= m; i++) {
    //         for(int j = 1; j <= n; j++) {
    //             if(text1[i-1] == text2[j-1]) {
    //                 dp[i][j] = dp[i-1][j-1] + 1;
    //             } else {
    //                 dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
    //             }
    //         }
    //     }
    //     return dp[m][n];
    // }

    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size(), n = text2.size();
        vector<int> dp(n+1, 0);
        for(int i = 1; i <= m; i++) {
            int pre = 0;
            for(int j = 1; j <= n; j++) {
                int tmp = dp[j];
                if(text1[i-1] == text2[j-1]) {
                    // 这里需要修改，记录i-1,j-1的值
                    dp[j] = pre + 1;
                } else {
                    dp[j] = max(dp[j], dp[j-1]);
                }
                pre = tmp;
            }
        }
        return dp[n];
    }
};