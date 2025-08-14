class Solution {
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        // 爬楼梯变种，主要取mode
        int mod = 1e9 + 7;
        vector<int> dp(high + 1);
        dp[0] = 1;
        int ans = 0;
        for(int i = 1; i <= high; ++i) {
            if(i >= zero) dp[i] += dp[i - zero];
            if(i >= one) dp[i] += dp[i - one];
            dp[i] %= mod;
            if(i >= low) {
                ans += dp[i];
                ans %= mod;
            }
        }
        return ans;
    }
};