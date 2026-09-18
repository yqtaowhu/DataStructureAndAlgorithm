class Solution {
public:
    // 从1-sqrt(n)中选择x个数，可重复
    // 完全背包最值问题
    // dp[i][j] 表示前i个数中，和为j的最小值
    // dp[i][j] = min(dp[i-1][j], dp[i-1][j-x*x] + 1)
    // dp[j] = min(dp[j], dp[j-x*x] + 1)
    int numSquares(int n) {
        vector<int> dp(n+1, INT_MAX);
        dp[0] = 0;
        for(int num = 1; num*num <= n; num++) {
            for(int i=0; i<=n; i++) {
                if(i-num*num >= 0) {
                    dp[i] = min(dp[i], dp[i-num*num] + 1);
                }
            }
        }
        return dp[n];
    }
};