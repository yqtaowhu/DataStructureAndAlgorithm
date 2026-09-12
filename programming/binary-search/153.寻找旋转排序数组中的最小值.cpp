/*
 * @lc app=leetcode.cn id=153 lang=cpp
 *
 * [153] 寻找旋转排序数组中的最小值
 */

// @lc code=start
// 套模板解法（左闭右开 [left, right)，红蓝染色），与 154 题共用同一模板
// 模板三句话：
//   1. 循环条件 left < right
//   2. 满足条件（蓝） → right = mid（mid 可能是答案，不能丢）
//   3. 不满足（红）   → left = mid + 1（mid 一定不是答案，排除）
//
// 染色规则：以 nums.back() 为「固定基准」
//   - 红色：nums[mid] > nums.back()，mid 在左段，最小值一定在 mid 右侧
//   - 蓝色：nums[mid] ≤ nums.back()，mid 在右段或就是最小值
// 不变量：最小值始终落在 [left, right) 内，循环结束时 left 即旋转点
class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size();          // 左闭右开
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] > nums.back()) {
                left = mid + 1;                     // 红：mid 不是最小值
            } else {
                right = mid;                        // 蓝：mid 可能就是最小值
            }
        }
        return nums[left];
    }
};
// @lc code=end

