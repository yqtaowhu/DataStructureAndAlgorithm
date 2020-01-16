/*
 * @lc app=leetcode.cn id=26 lang=cpp
 *
 * [26] 删除排序数组中的重复项
 */

// @lc code=start
class Solution {
public:
    // 双指针法，i,j快慢指针
    int removeDuplicates(vector<int>& nums) {
       int len = nums.size();
       if(len < 1) return len;
       int i = 0;
       for(int j =1; j < len; j++) {
           if(nums[j] != nums[i]) {
               nums[++i] = nums[j];
           }
       }
       return i+1;
    }
};
// @lc code=end

