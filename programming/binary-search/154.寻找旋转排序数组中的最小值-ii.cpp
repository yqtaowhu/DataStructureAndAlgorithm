/*
 * @lc app=leetcode.cn id=154 lang=cpp
 *
 * [154] 寻找旋转排序数组中的最小值 II
 */

// @lc code=start
// 套模板解法（左闭右开 [left, right)，红蓝染色），与 153 题共用同一模板
// 模板三句话：left < right；蓝 right = mid；红 left = mid + 1
//
// 与 153 的差别仅一步：先对尾部重复元素做「预处理」，把右端锁定到 end，
// 使得 nums[end] 可以作为「固定基准」（同 153 中 nums.back() 的地位），循环内部就能完全套 153 的模板。
//
// 预处理安全性：当 nums[end] == nums[0] 时，删除 end 位置不会丢答案
//   - 若 nums[0] 就是最小值 → nums[0] 仍在区间内，仍是候选
//   - 若最小值 < nums[0]  → 等于 nums[0] 的 end 位置一定不是最小值
// 预处理后：nums[end] != nums[0]，保证以 nums[end] 为基准时「左段 > nums[end]、右段 ≤ nums[end]」单调成立
class Solution {
public:
    int findMin(vector<int>& nums) {
        // 1) 预处理：跳过尾部与 nums[0] 相等的元素（最坏 O(n)，与经典 right-- 写法同量级）
        int end = nums.size() - 1;
        while (end > 0 && nums[end] == nums[0]) --end;

        // 2) 在 [0, end+1) 上套 153 模板，基准换成 nums[end]
        int left = 0, right = end + 1;              // 左闭右开
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] > nums[end]) {
                left = mid + 1;                     // 红：mid 在左段，不是最小值
            } else {
                right = mid;                        // 蓝：mid 在右段或就是最小值
            }
        }
        return nums[left];
    }
};
// @lc code=end

