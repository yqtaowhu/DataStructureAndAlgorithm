class Solution {
public:
    // 完全背包最值问题
    // dp[i][j] 表示使用前i种硬币，凑成j的最少硬币数
    // dp[i][j] = min(dp[i-1][j], dp[i][j-coins[i]]+1])  // 不选或选
    // dp[j] = min(dp[j], dp[j-coins[i]]+1])
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, INT_MAX/2);
        dp[0] = 0; // 初始化
        // 遍历nums
        for(auto coin : coins) {
            // 正序遍历amount
            for(int j=0; j<=amount; j++) {
                if(j >= coin) {
                    dp[j] = min(dp[j], dp[j-coin]+1);
                }
            }
        }
        return dp[amount] == INT_MAX/2 ? -1 : dp[amount];
        
    }
};