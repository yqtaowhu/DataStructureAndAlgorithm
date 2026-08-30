/*
 * @lc app=leetcode.cn id=153 lang=cpp
 *
 * [153] 寻找旋转排序数组中的最小值
 */

// @lc code=start
class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size();
        // 2 1
        // mid == right
        while(left < right) {
            int mid = left + (right-left) / 2;
            if(nums[mid] > nums.back()) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return nums[left];
    }
};
// @lc code=end

