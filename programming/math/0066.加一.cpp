/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0066.加一.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taoyanqi <taoyanqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 17:37:51 by taoyanqi          #+#    #+#             */
/*   Updated: 2025/11/13 17:37:52 by taoyanqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * @lc app=leetcode.cn id=66 lang=cpp
 *
 * [66] 加一
 */

// @lc code=start
class Solution {
public:
    // 问题不难，但是写bug free，不容易
    vector<int> plusOne(vector<int>& digits) {
        // carry 初始化1后续操作简单，直接模拟了+1
        int m=digits.size(), carry=1;
        for(int i=m-1; i>=0; i--) {
            int sum = digits[i]+carry;
            digits[i] = sum % 10;
            carry = sum/10;
            if(carry<1) {
                break;
            }
        }
        if(carry) {
            // 容器头插入
            digits.insert(digits.begin(), 1);
        }
        return digits;    
    }
};
// @lc code=end

