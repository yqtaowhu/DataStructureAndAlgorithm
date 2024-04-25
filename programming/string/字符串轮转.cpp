/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   字符串轮转.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taoyanqi <taoyanqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 20:52:49 by taoyanqi          #+#    #+#             */
/*   Updated: 2024/04/25 20:52:58 by taoyanqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * @lc app=leetcode.cn id=面试题 01.09 lang=cpp
 * @lcpr version=30121
 *
 * [面试题 01.09] 字符串轮转
 */


// @lcpr-template-start
using namespace std;
#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    bool isFlipedString(string s1, string s2) {
        return s1.size() == s2.size() && (s1 + s1).find(s2) != string::npos;
    }
    // waterbottle   0-8 1-9 2-10
    // bool isFlipedString(string s1, string s2) {
    //     int m = s1.size(), n = s2.size();
    //     if(m != n) return false;
    //     if(m==0) return true;
    //     // 反转位数
    //     for(int i=0; i < m; i++) {
    //         bool flags = true;
    //         // 元素位置
    //         for(int j=0; j < m; j++) {
    //             if(s1[(i+j) % n] != s2[j]) {
    //                 flags = false;
    //                 break;
    //             }
    //         }
    //         if (flags) return true;
    //     }
    //     return false;
    // }
};
// @lc code=end



/*
// @lcpr case=start
// "waterbottle"\n"erbottlewat"\n
// @lcpr case=end

// @lcpr case=start
// "aa"\n"aba"\n
// @lcpr case=end

 */

