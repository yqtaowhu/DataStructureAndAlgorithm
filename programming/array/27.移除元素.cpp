/*
 * @lc app=leetcode.cn id=27 lang=cpp
 *
 * [27] 移除元素
 */

// @lc code=start
class Solution {
public:
    // 双指针法，i，j快慢指针，简单题
    int removeElement(vector<int>& nums, int val) {
        int len = nums.size();
        if(len < 1) return 0;
        int i = 0, j = 0;
        for(j = 0; j<len; j++) {
            if(nums[j] != val) {
                nums[i++] = nums[j];
            }
        }
        return i;
    }
};
// @lc code=end

