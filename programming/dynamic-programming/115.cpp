class Solution {
public:
    // dp[i][j] 表示s[0...i-1] 中有多少个子串等于 t[0...j-1]
    int numDistinct(string s, string t) {
        int m = s.size(), n = t.size();
        vector<vector<unsigned long long>> dp(m+1, vector<unsigned long long>(n+1, 0));
        
        // 空字符串是任何字符串的一个子序列
        for(int i = 0; i <= m; ++i) dp[i][0] = 1;

        for(int i = 1; i <= m; ++i) {
            for(int j = 1; j <= n; ++j) {
                if(s[i-1] == t[j-1]) {
                    // 如果字符相等，可以选择匹配或不匹配
                    dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
                } else {
                    // 如果字符不等，只能选择不匹配
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[m][n];
    }
};