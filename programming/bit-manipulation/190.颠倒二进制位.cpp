/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   190.颠倒二进制位.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taoyanqi <taoyanqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 20:46:37 by taoyanqi          #+#    #+#             */
/*   Updated: 2024/04/10 20:46:38 by taoyanqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * @lc app=leetcode.cn id=190 lang=cpp
 *
 * [190] 颠倒二进制位
 */

// @lc code=start
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res = 0;
        for(int i=0; i<32; i++) {
            if(n & 1) {
                res += 1 << (32 - i - 1);
            }
            n = n >> 1;
        }
        return res;
    }
    /*
    uint32_t reverseBits(uint32_t n) {
        uint32_t ret=0;
        for(int i=0; i<32; i++) {
            ret = (ret*2) + (n & 0x1);
            n /=2 ;
        }
        return ret;
    }
    */
};
// @lc code=end

