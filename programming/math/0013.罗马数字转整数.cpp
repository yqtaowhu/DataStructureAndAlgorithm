/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0013.罗马数字转整数.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taoyanqi <taoyanqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 12:33:17 by taoyanqi          #+#    #+#             */
/*   Updated: 2025/10/24 17:14:24 by taoyanqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * @lc app=leetcode.cn id=13 lang=cpp
 *
 * [13] 罗马数字转整数
 */

// @lc code=start
class Solution {
public:
    // 很简单，只需要考虑两种情况
    int romanToInt(string s) {
        unordered_map<char,int> hash = {
            {'I',1},
            {'V',5},
            {'X',10},
            {'L',50},
            {'C',100},
            {'D', 500},
            {'M', 1000}
        };
        int res = 0;
        // 当前位置比后面位置小就-， 否则就加
        for(int i=0; i<s.size()-1; i++) {
            if(hash[s[i]] < hash[s[i+1]]) {
                res -= hash[s[i]];
            } else {
                res += hash[s[i]];
            }
        }
        // 最后一位一定是加
        res += hash[s[s.size()-1]];
        return res;
    }
};
// @lc code=end

