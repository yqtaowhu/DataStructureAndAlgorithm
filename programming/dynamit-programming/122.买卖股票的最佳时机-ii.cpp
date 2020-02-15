/*
 * @lc app=leetcode.cn id=122 lang=cpp
 *
 * [122] 买卖股票的最佳时机 II
 */

// @lc code=start
class Solution {
public:
int maxProfit(vector<int>& prices) {
    int dp_i_0 = 0, dp_i_1 = INT_MIN;
    for(int i=0; i<prices.size(); i++) {
        int tmp = dp_i_0;
        dp_i_0 = max(dp_i_0, dp_i_1 + prices[i]);
        dp_i_1 = max(dp_i_1, tmp - prices[i]);
    }
    return dp_i_0;
}
};
// @lc code=end

