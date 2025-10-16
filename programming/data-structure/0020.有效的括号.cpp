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
    bool isValid(string s) {
        stack<char> st;
        for(auto c: s) {
            if(c == '(' || c == '[' || c == '{') {
                st.push(c);
            } else {
                // 注意判断栈空
                if(st.empty()) return false;
                char t = st.top();
                st.pop();
                if((c == ')' &&  t != '(') || (c == ']' && t != '[')  || (c == '}' && t != '{')) {
                    return false;
                }
            }
        }
        return st.empty();
    }
};
// @lc code=end

