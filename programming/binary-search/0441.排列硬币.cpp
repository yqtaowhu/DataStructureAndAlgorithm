/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0441.排列硬币.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taoyanqi <taoyanqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/31 by taoyanqi                        #+#    #+#             */
/*   Updated: 2026/08/31 by taoyanqi                        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// 441. 排列硬币
// 二分行数：前 n 行需要 n(n+1)/2 枚硬币，单调递增
// 套模板的最大值技巧：找第一个 n(n+1)/2 > k 的行数再减一，即完整行数
class Solution {
public:
    int arrangeCoins(int k) {
        long long left = 1, right = (long long)k + 1;
        while (left < right) {
            long long mid = left + (right - left) / 2;
            if (mid * (mid + 1) / 2 > k) right = mid;   // mid 行放不下
            else left = mid + 1;                        // mid 行放得下，还能更多
        }
        return left - 1;
    }
};
