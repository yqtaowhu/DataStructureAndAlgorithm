/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3370.仅含置位位的最小整数.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taoyanqi <taoyanqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 17:09:26 by taoyanqi          #+#    #+#             */
/*   Updated: 2025/09/23 17:10:32 by taoyanqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

class Solution {
public:
    int bit_width(int n) {
        int res = 0;
        while(n) {
            res++;
            n = n >> 1;
        }
        return res;
    }
    int smallestNumber(int n) {
        int w = bit_width(n);
        return (1 << w) - 1;
    }

    int smallestNumber_2(int n) {
        return (1 << bit_width((uint32_t) n)) - 1;
    }
};