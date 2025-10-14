/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0007.整数反转.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taoyanqi <taoyanqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 17:21:09 by taoyanqi          #+#    #+#             */
/*   Updated: 2025/10/14 17:21:09 by taoyanqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

class Solution {
public:
    int reverse(int x) {
        int res = 0;
        // mod， 对于负数同样成立
        while(x != 0) {
            // 前置判断
            if(res > INT_MAX / 10 || res < INT_MIN / 10) {
                return 0;
            }
            int digit = x % 10;
            res = res * 10 + digit;
            x = x / 10;
        }
        return res;
    }
};