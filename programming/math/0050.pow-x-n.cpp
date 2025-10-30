/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0050.pow-x-n.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taoyanqi <taoyanqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 09:32:33 by taoyanqi          #+#    #+#             */
/*   Updated: 2025/10/30 09:32:39 by taoyanqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * @lc app=leetcode.cn id=50 lang=cpp
 *
 * [50] Pow(x, n)
 */

// @lc code=start
class Solution {
public:
    // 幂很大，使用快速幂
    double myPow(double x, int n) {
        long long exp = n;
        // 如果exp<0,转成为正数运算
        if(exp < 0) {
            x = 1/x;
            exp = -exp;
        }
    	double result = 1.0;
        // 快速幂的模板
    	while (exp) {
            // result在最低位相乘
    		if (exp & 1) {
    			result *= x;
    		}
    		exp >>= 1;
    		x *= x;
    	}
    	return result;
    }
};
// @lc code=end

