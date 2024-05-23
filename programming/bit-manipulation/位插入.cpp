/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   位插入.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taoyanqi <taoyanqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 20:30:58 by taoyanqi          #+#    #+#             */
/*   Updated: 2024/05/23 20:31:26 by taoyanqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// https://leetcode.cn/problems/insert-into-bits-lcci/description/?envType=study-plan-v2&envId=cracking-the-coding-interview
class Solution {
public:
    int insertBits(int N, int M, int i, int j) {
        // i-j 置0
        for(int k=i; k <=j; k++) {
            N &=  ~(1 << k);
        }
        return N + (M << i);
    }
};