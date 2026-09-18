/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0540.有序数组中的单一元素.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taoyanqi <taoyanqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/30 by taoyanqi                        #+#    #+#             */
/*   Updated: 2026/08/30 by taoyanqi                        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// 540. 有序数组中的单一元素
// 红蓝染色：红区 [0, s) 成对且 nums[mid] == nums[mid ^ 1]，
// 蓝区 [s, n-1] 规律破坏；mid ^ 1 恰好是 mid 的配对搭档下标（偶数取+1，奇数取-1）
// 套左闭右开模板找第一个 check 为 false 的位置，分界点即单一元素下标 s（必为偶数）
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        // 左闭右开 [left, right)：check = 是否仍在成对区（红区）
        // mid ^ 1 恰好是 mid 的配对搭档下标（偶数取+1，奇数取-1）
        // mid ^ 1 == n 仅当 mid = n-1，此时 mid 必在蓝区（s ≤ n-1），判为不匹配
        int n = nums.size();
        int left = 0, right = n;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if ((mid ^ 1) < n && nums[mid] == nums[mid ^ 1]) {
                left = mid + 1; // 仍在成对区，单一元素在右侧
            } else {
                right = mid;    // 规律已破坏，单一元素在 [left, mid] 中
            }
        }
        return nums[left];      // left == right == 分界点
    }
};
