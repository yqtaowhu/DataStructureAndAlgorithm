/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1608.特殊数组的特征值.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taoyanqi <taoyanqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/30 by taoyanqi                        #+#    #+#             */
/*   Updated: 2026/08/30 by taoyanqi                        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// 1608. 特殊数组的特征值
// 枚举 x ∈ [1, n]，排序后用 lower_bound 计数 >= x 的元素个数，恰好等于 x 即答案
class Solution {
public:
    int specialArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int x = 1; x <= n; x++) {
            // 第一个 >= x 的下标之后全满足，个数 = n - lower_bound(nums, x)
            int cnt = n - (lower_bound(nums.begin(), nums.end(), x) - nums.begin());
            if (cnt == x) return x;
        }
        return -1;
    }
};
