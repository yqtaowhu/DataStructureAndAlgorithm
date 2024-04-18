/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   67.二进制求和.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taoyanqi <taoyanqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 20:45:16 by taoyanqi          #+#    #+#             */
/*   Updated: 2024/04/18 20:45:25 by taoyanqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * @lc app=leetcode.cn id=67 lang=cpp
 *
 * [67] 二进制求和
 */

// @lc code=start
class Solution {
public:
    // 11 1
    string addBinary(string a, string b) {
        int m = a.size(), n = b.size();
        int carry = 0;
        string res = "";
        while(m >= 1 || n >= 1 || carry) {
            // 注意string to int atoi函数，而不是直接int()
            int x = m >= 1 ? a[m-1] - '0' : 0;
            int y = n >= 1 ? b[n-1] - '0' : 0;
            int tmp = x + y + carry;
            // cout << x << " " << y << " " << tmp << endl;
            carry = tmp / 2;
            res = to_string(tmp % 2) + res;
            m--;
            n--;
        }
        return res;
    }
};
// @lc code=end

