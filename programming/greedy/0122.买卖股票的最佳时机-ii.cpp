/*
 * @lc app=leetcode.cn id=122 lang=cpp
 *
 * [122] 买卖股票的最佳时机 II
 */

// @lc code=start
class Solution {
public:
    // 贪心：不限交易次数，把所有「相邻上涨」的收益全部吃下即为最大利润。
    // 等价于在每个局部低点买、局部高点卖，连续上涨可拆成每天买卖。
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        for (int i = 1; i < (int)prices.size(); i++) {
            profit += max(0, prices[i] - prices[i - 1]); // 只累加正收益
        }
        return profit;
    }
};
// @lc code=end
