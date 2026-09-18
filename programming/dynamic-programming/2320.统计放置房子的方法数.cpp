class Solution {
public:
    int countHousePlacements(int n) {
        int mod = 1e9 + 7;
        vector<long long> dp(n + 1, 0);
        dp[0]= 1;
        dp[1]= 2;
        for(int i=2; i <= n; i++) {
            dp[i] = (dp[i-2] + dp[i-1]) % mod;
        }
        return dp[n] * dp[n] % mod;
    }
};