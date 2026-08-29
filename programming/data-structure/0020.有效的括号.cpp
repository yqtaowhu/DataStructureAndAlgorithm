/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0020.有效的括号.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taoyanqi <taoyanqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 20:03:21 by taoyanqi          #+#    #+#             */
/*   Updated: 2025/10/16 12:46:09 by taoyanqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */

// @lc code=start
class Solution {
public:
    // 遇到左括号直接压入对应的右括号，遇到右括号只需判断是否与栈顶一致
    bool isValid(string s) {
        stack<char> st;
        for(char c : s) {
            if(c == '(') {
                st.push(')');
            } else if(c == '[') {
                st.push(']');
            } else if(c == '{') {
                st.push('}');
            } else {
                // 注意判断栈空：右括号多干左括号的情况
                if(st.empty() || st.top() != c) {
                    return false;
                }
                st.pop();
            }
        }
        return st.empty();
    }
};
// @lc code=end

