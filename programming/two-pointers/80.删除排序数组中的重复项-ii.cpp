/*
 * @lc app=leetcode.cn id=80 lang=cpp
 *
 * [80] 删除排序数组中的重复项 II
 */

// @lc code=start
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.empty()) return 0;
       int left=1, right=1, count=1;
       while(right < nums.size()) {
           if(nums[right] == nums[right-1]) {
               count += 1;
           } else {
               count = 1;
           }
           if(count <=2) {   //满足条件，left++
                nums[left++] = nums[right];
           }
           right++;
       }
       return left;
    }
};
// @lc code=end

