/*
 * @lc app=leetcode.cn id=55 lang=cpp
 *
 * [55] 跳跃游戏
 */

// @lc code=start
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int m = nums.size();
        if(m==0) return false;
        int max_step = nums[0];
        for(int i=1; i<m && i<=max_step; i++) {
            max_step = max(max_step, i+nums[i]);
            //提前结束
            if(max_step >= m-1)
                return true;
        }
        return max_step >= m-1;
    }
};
// @lc code=end

