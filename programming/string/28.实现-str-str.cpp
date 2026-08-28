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


// @lc code=start
class Solution {
public:
    int strStr(string haystack, string needle) {
        int m = haystack.size(), n = needle.size();
        if (n == 0) return 0;
        if (n > m) return -1;

        // 1. 构建模式串的 next 数组：next[i] 表示 needle[0..i] 的最长相等前后缀长度
        vector<int> next(n, 0);
        for (int i = 1, len = 0; i < n; ) {
            if (needle[i] == needle[len]) {
                next[i++] = ++len;
            } else if (len > 0) {
                len = next[len - 1];  // 回退到更短的相等前后缀
            } else {
                next[i++] = 0;
            }
        }

        // 2. KMP 匹配：主串指针 i 永不回退，失配时仅模式串指针 j 回退
        for (int i = 0, j = 0; i < m; ) {
            if (haystack[i] == needle[j]) {
                i++; j++;
                if (j == n) return i - n;  // 匹配成功，返回起点
            } else if (j > 0) {
                j = next[j - 1];
            } else {
                i++;
            }
        }
        return -1;
    }
};
// @lc code=end

