/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   整数转换.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taoyanqi <taoyanqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 20:42:00 by taoyanqi          #+#    #+#             */
/*   Updated: 2024/05/23 20:42:13 by taoyanqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


// https://leetcode.cn/problems/convert-integer-lcci/solutions/191397/yi-huo-jie-fa-python-3-c-by-z1m/?envType=study-plan-v2&envId=cracking-the-coding-interview
class Solution {
public:
    // 常规直接统计每一位是不是相同
    // int convertInteger(int A, int B) {
    //     int res = 0;
    //     for(int i=0; i < 32; i++) {
    //         int a = A & (1 << i);
    //         int b = B & (1 << i);
    //         if (a != b) {
    //             res++;
    //         }
    //     }
    //     return res;
    // }

    int convertInteger(int A, int B) {
        int res = 0;
        unsigned c = A ^ B; // 异或操作
        // 统一1的个数，只有不同才为1
        while(c) {
            c = c & (c - 1);
            res++;
        }
        return res;

    }
};