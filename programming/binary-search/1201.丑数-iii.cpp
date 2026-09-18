/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1201.丑数-iii.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taoyanqi <taoyanqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/31 by taoyanqi                        #+#    #+#             */
/*   Updated: 2026/08/31 by taoyanqi                        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// 1201. 丑数 III
// 二分答案 x：count(x) = [1, x] 中能被 a/b/c 至少一个整除的个数（容斥原理）
// count 关于 x 单调不减，套模板找第一个 count(x) >= n 的位置
class Solution {
public:
    int nthUglyNumber(int n, int a, int b, int c) {
        long long ab = lcm((long long)a, (long long)b);
        long long ac = lcm((long long)a, (long long)c);
        long long bc = lcm((long long)b, (long long)c);
        long long abc = lcm(ab, (long long)c);
        auto count = [&](long long x) {     // 容斥：+单个 -两两交集 +三者交集
            return x / a + x / b + x / c - x / ab - x / ac - x / bc + x / abc;
        };
        long long left = 1, right = (long long)min({a, b, c}) * n;  // 第 n 个丑数不超过 min*n
        while (left < right) {
            long long mid = left + (right - left) / 2;
            if (count(mid) >= n) right = mid;
            else left = mid + 1;
        }
        return left;
    }
};
