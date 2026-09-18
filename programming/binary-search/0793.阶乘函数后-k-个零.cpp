/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0793.阶乘函数后-k-个零.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taoyanqi <taoyanqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/31 by taoyanqi                        #+#    #+#             */
/*   Updated: 2026/08/31 by taoyanqi                        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// 793. 阶乘函数后 K 个零
// 二分 n：zeros(n) = n/5 + n/25 + ... 关于 n 单调不减，找第一个 zeros(n) >= k 的位置
// 尾零数每经过 5 的倍数才至少 +1，故每个 k 的原像大小为 0 或 5
class Solution {
public:
    int preimageSizeFZF(int k) {
        auto zeros = [&](long long n) {     // n! 的尾零数
            long long cnt = 0;
            while (n) cnt += n /= 5;
            return cnt;
        };
        long long left = 0, right = 5LL * (k + 1);  // zeros(5(k+1)) > k
        while (left < right) {
            long long mid = left + (right - left) / 2;
            if (zeros(mid) >= k) right = mid;
            else left = mid + 1;
        }
        return zeros(left) == k ? 5 : 0;    // 恰为 k 则 [left, left+4] 共 5 个解
    }
};
