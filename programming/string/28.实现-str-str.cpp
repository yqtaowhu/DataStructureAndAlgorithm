/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   28.实现-str-str.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taoyanqi <taoyanqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 20:15:16 by taoyanqi          #+#    #+#             */
/*   Updated: 2024/04/22 20:15:17 by taoyanqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * @lc app=leetcode.cn id=28 lang=cpp
 *
 * [28] 实现 strStr()
 */

// @lc code=start
class Solution {
public:
    int strStr(string haystack, string needle) {
        int m = haystack.size(), n = needle.size();
        if(n > m) return -1;
        for(int i=0; i <= m-n; i++) {
            int k = i, j = 0;
            while(k < m && j < n && haystack[k] == needle[j]) {
                k++;
                j++;
            }
            if(j == n) return i;
        }
        return -1;
    }
};
// @lc code=end

