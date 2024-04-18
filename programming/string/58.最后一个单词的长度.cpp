/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   58.最后一个单词的长度.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taoyanqi <taoyanqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 21:27:35 by taoyanqi          #+#    #+#             */
/*   Updated: 2024/04/18 21:27:40 by taoyanqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * @lc app=leetcode.cn id=58 lang=cpp
 *
 * [58] 最后一个单词的长度
 */

// @lc code=start
class Solution {
public:
   int lengthOfLastWord(string s) {
       // 实现很精妙，从后往前会更简单
       int i=s.size()-1,len=0;
       while (s[i]==' '&&i>=0) i--;
       while (s[i]!=' '&&i>=0) {
           i--;len++;
       }
       return len;
    }
};
// @lc code=end

