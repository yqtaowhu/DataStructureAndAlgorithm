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
        // 特殊情况
        if(len <= 0 ) return 0;
        if(target > nums[len-1]) return len;

        int left = 0, right = len - 1;
        // 模板代码
        while(left < right) {
            int mid = (left + right) >> 1;
            if(nums[mid] >= target) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};
// @lc code=end

