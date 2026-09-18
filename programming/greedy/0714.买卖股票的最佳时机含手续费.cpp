/*
 * @lc app=leetcode.cn id=714 lang=cpp
 *
 * [714] 买卖股票的最佳时机含手续费
 */

// @lc code=start
class Solution {
public:
    // 贪心 + 状态机：cash = 不持股时的最大利润，hold = 持股时的最大利润。
    // 每天在「不动」与「买/卖」之间取最优；卖出时扣一次手续费 fee。
    int maxProfit(vector<int>& prices, int fee) {
        int cash = 0, hold = -prices[0]; // 第 0 天：不持股为 0，持股即买入
        for (int i = 1; i < (int)prices.size(); i++) {
            cash = max(cash, hold + prices[i] - fee); // 今天卖出
            hold = max(hold, cash - prices[i]);       // 今天买入
        }
        return cash; // 最后一定不持股利润最大
    }
};
// @lc code=end
