/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1802.有界数组中指定下标处的最大值.cpp                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taoyanqi <taoyanqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/31 by taoyanqi                        #+#    #+#             */
/*   Updated: 2026/08/31 by taoyanqi                        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// 1802. 有界数组中指定下标处的最大值
// 二分峰值 x：check(x) = 构造数组的总和 <= maxSum
// 最大化 x：套模板的最大值技巧——找第一个 check 为 false 的位置再减一
class Solution {
public:
    int maxValue(int n, int index, int maxSum) {
        // 峰值一侧长度 len 之和（不含峰值）：从 x-1 递减到 1，不足补 1
        auto sideSum = [](long long x, long long len) -> long long {
            if (len == 0) return 0;
            if (x > len) return (2 * x - len - 1) * len / 2;  // (x-1)+...+(x-len)
            return x * (x - 1) / 2 + (len - x + 1);           // 递减到 1，其余为 1
        };
        auto check = [&](long long x) {
            return x + sideSum(x, index) + sideSum(x, n - 1 - index) <= maxSum;
        };
        long long left = 1, right = maxSum + 1LL;
        while (left < right) {
            long long mid = left + (right - left) / 2;
            if (check(mid)) left = mid + 1;   // mid 可行，答案可能更大
            else right = mid;                 // mid 超预算，可能是分界
        }
        return left - 1;
    }
};
