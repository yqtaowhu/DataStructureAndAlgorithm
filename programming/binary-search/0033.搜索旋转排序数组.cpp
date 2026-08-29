/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0033.搜索旋转排序数组.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taoyanqi <taoyanqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 12:59:31 by taoyanqi          #+#    #+#             */
/*   Updated: 2025/11/27 12:42:02 by taoyanqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


// ===================== 套模板解法（左闭右开 [left, right)，红蓝染色） =====================
// 模板三句话：
//   1. 循环条件 left < right
//   2. 满足条件 → right = mid（mid 可能是答案，不能丢）
//   3. 不满足   → left = mid + 1（mid 一定不是答案，排除）

// 解法一：一次二分，直接把「哪半边有序」写成 check 条件
class Solution3 {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size();   // 左闭右开
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) return mid;
            // 左半 [0, mid] 有序：target 落在 [nums[0], nums[mid]) 内 → 只可能在左半
            if (nums[0] <= nums[mid]) {
                if (nums[0] <= target && target < nums[mid]) {
                    right = mid;        // 答案在左半
                } else {
                    left = mid + 1;     // 答案一定不在左半
                }
            } else { // 右半 (mid, n-1] 有序：target 落在 (nums[mid], nums[n-1]] 内 → 只可能在右半
                if (nums[mid] < target && target <= nums.back()) {
                    left = mid + 1;
                } else {
                    right = mid;
                }
            }
        }
        return -1;
    }
};

// 解法二：两次二分，全部套同一个模板
// 第一步：套模板找旋转点（即最小值位置，同 153 题）
// 第二步：把数组按旋转点“展开”成虚拟有序数组，套 lower_bound 模板找 target
class Solution4 {
public:
    // 返回最小值下标：check(mid) = nums[mid] > nums.back() → mid 在旋转点左侧，答案在右
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size();   // 左闭右开
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] > nums.back()) {
                left = mid + 1;   // mid 一定不是最小值
            } else {
                right = mid;      // mid 可能是最小值
            }
        }
        return left;
    }

    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int rot = findMin(nums);
        // 虚拟下标 i 对应真实下标 (i + rot) % n，虚拟数组全局有序
        // 套 lower_bound：找第一个 nums[真实] >= target 的虚拟下标
        int left = 0, right = n;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[(mid + rot) % n] >= target) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        int real = (left + rot) % n;
        return (left < n && nums[real] == target) ? real : -1;
    }
};
