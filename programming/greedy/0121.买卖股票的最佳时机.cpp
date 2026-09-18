/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 买卖股票的最佳时机
 */

// @lc code=start
class Solution {
public:
    // 贪心：只能买卖一次，遍历时维护「历史最低价」，
    // 每一天都假设「在今天以最低价买入、今天卖出」，取利润最大者。
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX, best = 0;
        for (int p : prices) {
            minPrice = min(minPrice, p);        // 到目前为止的最低买入价
            best = max(best, p - minPrice);     // 今天卖出的最大利润
        }
        return best;
    }
};
// @lc code=end
