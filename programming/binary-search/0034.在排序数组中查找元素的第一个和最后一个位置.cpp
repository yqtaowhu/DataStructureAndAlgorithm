/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   34.在排序数组中查找元素的第一个和最后一个位置.cpp                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taoyanqi <taoyanqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 17:28:35 by taoyanqi          #+#    #+#             */
/*   Updated: 2025/10/24 17:28:36 by taoyanqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

class Solution {
public:
    int lower_bound(vector<int> &nums, int target) {
        // lower_bound 返回最小的满足 nums[i] >= target 的下标 i
        int left=0, right = nums.size();
        // 左闭右开
        while(left < right) {
            int mid = left + (right - left) / 2;
            if(nums[mid] >= target) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        // 循环结束后 left = right
        // 此时 nums[left-1] < target 而 nums[left] = nums[right] >= target
        // 所以 left 就是第一个 >= target 的元素下标
        return left;
    }

    int upper_bound(vector<int> &nums, int target) {
        int left=0, right = nums.size();
        // 左闭右开
        while(left < right) {
            int mid = left + (right - left ) / 2;
            if(nums[mid] > target) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int start = lower_bound(nums, target);
        if (start == nums.size() || nums[start] != target) {
            return {-1, -1}; // nums 中没有 target
        }
        // 如果 start 存在，那么 end 必定存在
        int end = upper_bound(nums, target) - 1;
        return vector<int>{start, end};
    }
};