/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0012.整数转罗马数字.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taoyanqi <taoyanqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 12:33:14 by taoyanqi          #+#    #+#             */
/*   Updated: 2025/10/24 17:14:26 by taoyanqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * @lc app=leetcode.cn id=12 lang=cpp
 *
 * [12] 整数转罗马数字
 */

// @lc code=start
class Solution {
public:
    //由于加减的不同，所以讲IV这种看出一个新的字符，然后从大到小使用较大的字符
    string intToRoman(int num) {
        vector<string> symbol = { "M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I" };
        vector<int> value = { 1000,900,500,400, 100, 90,  50, 40,  10, 9,   5,  4,   1 };
        string res;
        for(int i=0; num != 0 ; i++) {
            while(num >= value[i]) {
                res += symbol[i];
                num -= value[i];
            }
        }
        return res;
    }
};
// @lc code=end

