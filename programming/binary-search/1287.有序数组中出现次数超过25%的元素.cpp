/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1287.有序数组中出现次数超过25%的元素.cpp                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taoyanqi <taoyanqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/30 by taoyanqi                        #+#    #+#             */
/*   Updated: 2026/08/30 by taoyanqi                        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// 1287. 有序数组中出现次数超过25%的元素
// 出现次数 > n/4 的元素区间长度 > n/4，必覆盖 {n/4, n/2, 3n/4} 中某个候选位置
// 对每个候选用 upper_bound - lower_bound 统计出现次数
class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int n = arr.size();
        for (int idx : {n / 4, n / 2, 3 * n / 4}) {
            int v = arr[idx];
            int l = lower_bound(arr.begin(), arr.end(), v) - arr.begin();
            int r = upper_bound(arr.begin(), arr.end(), v) - arr.begin();
            if (r - l > n / 4) return v;
        }
        return -1; // 题目保证存在，理论不可达
    }
};
