/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2226.每个小孩最多能分到多少糖果.cpp                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taoyanqi <taoyanqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/31 by taoyanqi                        #+#    #+#             */
/*   Updated: 2026/08/31 by taoyanqi                        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// 2226. 每个小孩最多能分到多少糖果
// 「最大化最小值」经典题：二分每人糖果 c，check(c) = sum(pile/c) >= k
// c 越大越难满足，check 单调递减；套模板的最大值技巧：找第一个 check 为 false 的位置再减一
class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        auto check = [&](long long c) {     // 每人至少 c 颗能服务几个小孩
            long long cnt = 0;
            for (int pile : candies) cnt += pile / c;  // 堆内连续切分，多余丢弃
            return cnt >= k;
        };
        long long left = 1;
        long long right = accumulate(candies.begin(), candies.end(), 0LL) / k + 1;
        while (left < right) {
            long long mid = left + (right - left) / 2;
            if (check(mid)) left = mid + 1;   // mid 可行，答案可能更大
            else right = mid;                 // mid 不可行，可能是分界
        }
        return left - 1;
    }
};
