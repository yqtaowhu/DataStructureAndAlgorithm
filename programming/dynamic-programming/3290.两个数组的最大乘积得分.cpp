class Solution {
public:
    // dp[i][j] = max(dp[i-1][j], dp[i-1][j-1] + a[j-1] * b[i-1])
    // dp[j] = max(dp[j-1], dp[j-1] + a[j-1] * b[i])
    long long maxScore(vector<int>& a, vector<int>& b) {
        vector<long long> dp(5, LLONG_MIN);
        dp[0] = 0;
        
        for(int i = 0; i < b.size(); ++i) {
            // 从后往前更新，避免重复使用本轮更新的值
            for(int j = min(4, i + 1); j >= 1; --j) {
                if(dp[j-1] != LLONG_MIN) {
                    dp[j] = max(dp[j], dp[j-1] + (long long)a[j-1] * b[i]);
                }
            }
        }
        
        return dp[4];
    }
};