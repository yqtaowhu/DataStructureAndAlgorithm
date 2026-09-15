/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0367.有效的完全平方数.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taoyanqi <taoyanqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/31 by taoyanqi                        #+#    #+#             */
/*   Updated: 2026/08/31 by taoyanqi                        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// 367. 有效的完全平方数
// 69 的变体：二分找第一个平方 > num 的位置，减一即 floor(sqrt(num))，
// 判断其平方是否恰为 num 即可（用 long long 防止 mid*mid 溢出）
class Solution {
public:
    bool isPerfectSquare(int num) {
        long long left = 1, right = (long long)num + 1;
        while (left < right) {
            long long mid = left + (right - left) / 2;
            if (mid * mid > num) right = mid;   // 平方超了，mid 可能是分界
            else left = mid + 1;                // 平方没超，还能更大
        }
        return (left - 1) * (left - 1) == num;
    }
};
