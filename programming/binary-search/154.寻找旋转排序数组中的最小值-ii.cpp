/*
 * @lc app=leetcode.cn id=154 lang=cpp
 *
 * [154] 寻找旋转排序数组中的最小值 II
 */

// @lc code=start
class Solution {
public:
    int findMin(vector<int>& nums) {
        int left =0, right = nums.size()-1;
        while(left < right) {
            int mid = (left + right) >> 1;
            if(nums[mid] > nums[right]) {
                left = mid+1;
            } else if(nums[mid] == nums[right]) {
                right--;
            } else {
                right = mid;
            }
        }
        return nums[left];
    }
};
// @lc code=end

