/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1539.第k个缺失的正整数.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taoyanqi <taoyanqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/30 by taoyanqi                        #+#    #+#             */
/*   Updated: 2026/08/30 by taoyanqi                        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// 1539. 第 k 个缺失的正整数
// missing(i) = arr[i] - i - 1：下标 i 之前缺失的正整数个数（严格递增保证单调不减）
// 套模板找第一个 missing(i) >= k 的下标 left，答案前交错着 left 个数组元素和 k 个缺失数
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        // 左闭右开 [left, right)：check = 该下标前缺失数已达 k
        int left = 0, right = arr.size();
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] - mid - 1 >= k) {
                right = mid;    // 缺失数已 >= k，答案在 mid 或其左侧
            } else {
                left = mid + 1; // 缺失数不足 k，答案在右侧
            }
        }
        return k + left;        // left 可能等于 n（数组内缺失不足 k）
    }
};
