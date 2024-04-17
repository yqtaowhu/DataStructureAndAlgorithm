/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   70.爬楼梯.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taoyanqi <taoyanqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 20:53:25 by taoyanqi          #+#    #+#             */
/*   Updated: 2024/04/17 20:53:26 by taoyanqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70] 爬楼梯
 */

// @lc code=start
class Solution {
public:
    int climbStairs(int n) {
       if(n<=2) return n;
       int a=1,b=2;
       int res = 0;
       for(int i=3; i<=n; i++) {
           res = a+b;
           a = b;
           b = res;
       } 
       return res;
    }
};
// @lc code=end

