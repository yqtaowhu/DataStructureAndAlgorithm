/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0081.搜索旋转排序数组-ii.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taoyanqi <taoyanqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 12:46:13 by taoyanqi          #+#    #+#             */
/*   Updated: 2025/11/27 12:46:19 by taoyanqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// 套模板解法（左闭右开 [left, right)，红蓝染色），同 33 题写法，仅多处理重复元素
// 模板三句话：left < right；满足条件 right = mid；不满足 left = mid + 1
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int left = 0, right = nums.size();   // 左闭右开
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) return true;
            // 与 33 的差异一：区间起点会右移，判有序用 nums[left] 而不是 nums[0]
            // 与 33 的差异二：重复元素无法判断哪半边有序，只能两端各收缩一格（该值必 ≠ target）
            if (nums[left] == nums[mid] && nums[mid] == nums[right - 1]) {
                ++left;
                --right;
            } else if (nums[left] <= nums[mid]) { // 左半 [left, mid] 有序
                if (nums[left] <= target && target < nums[mid]) {
                    right = mid;        // 答案在左半
                } else {
                    left = mid + 1;     // 答案一定不在左半
                }
            } else { // 右半 (mid, right-1] 有序
                if (nums[mid] < target && target <= nums[right - 1]) {
                    left = mid + 1;
                } else {
                    right = mid;
                }
            }
        }
        return false;
    }
};