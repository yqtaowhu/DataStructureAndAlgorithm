/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   121.买卖股票的最佳时机.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taoyanqi <taoyanqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 20:59:20 by taoyanqi          #+#    #+#             */
/*   Updated: 2024/04/12 20:59:23 by taoyanqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 买卖股票的最佳时机
 */

// @lc code=start
class Solution {
public:
int maxProfit(vector<int>& prices) {
    int size = prices.size();
    if(size <= 1) return 0;
    int last = prices[0], res = 0;
    for(int i=1; i < size; i++) {
        if(prices[i] <= last) {
            last = prices[i];
        } else {
            res = max(res, prices[i] - last);
        }
    }
    return res;
}

int maxProfit(vector<int>& prices) {
    int dp_i_0 = 0, dp_i_1 = INT_MIN;
    for(int i=0; i<prices.size(); i++) {
        dp_i_0 = max(dp_i_0, dp_i_1 + prices[i]);
        dp_i_1 = max(dp_i_1, -prices[i]);
    }
    return dp_i_0;
}
};
// @lc code=end

