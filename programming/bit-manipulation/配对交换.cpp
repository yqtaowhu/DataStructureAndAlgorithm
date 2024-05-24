/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   配对交换.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taoyanqi <taoyanqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 20:32:15 by taoyanqi          #+#    #+#             */
/*   Updated: 2024/05/24 20:32:16 by taoyanqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

class Solution {
public:
    // int exchangeBits(int num) {
    //     for(int i=0; i<31; i += 2) {
    //         // 得到第i位数字
    //         int m = num & (1 << i);
    //         int n = num & (1 << i + 1);
    //         //cout << m << " " << n << endl;
    //         // num = num + 2*m - m  - n / 2
    //         num = num + m - (n >> 1);
    //     }
    //     return num;
    // }
    int exchangeBits(int num) {
        return (((num & 0x55555555) << 1) | ((num & 0xaaaaaaaa) >> 1));
    }
};