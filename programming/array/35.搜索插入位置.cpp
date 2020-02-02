/*
 * @lc app=leetcode.cn id=35 lang=cpp
 *
 * [35] 搜索插入位置
 */

// @lc code=start
class Solution {
public:
    // 二分搜索，需要注意的是left,right的范围
    int searchInsert(vector<int>& nums, int target) {
       int len = nums.size();
       if(len < 1) return 0;
       if(target > nums[len-1]) return len;
       int left = 0, right = len;
       while(left < right) {
           int mid = (left + right) >> 1;
           if(nums[mid] == target) {
               return mid;
           } else if(nums[mid] > target) {
               right = mid;
           } else {
               // 一般这个固定的
               left = mid + 1;
           }
       }
       return left; 
    }
};
// @lc code=end

