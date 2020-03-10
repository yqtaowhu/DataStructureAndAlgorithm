/*
 * @lc app=leetcode.cn id=198 lang=cpp
 *
 * [198] 打家劫舍
 */

// @lc code=start
class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.empty()) return 0;
        // dp[i]:第i个房间可获得的最大金额
        int len = nums.size();
        // vector<int> dp(len + 1, 0);
        // dp[1] = nums[0];
        // for(int i=2; i<=len; i++) {
        //     dp[i] = max(dp[i-1], dp[i-2] + nums[i-1]); //两种选择，拿或者不拿
        // }
        // return dp[len];
        int pre = 0, cur = nums[0];
        for(int i=2; i<=len; i++) {
            int temp = max(pre + nums[i-1], cur);
            pre = cur;
            cur = temp;
        }
        return cur;
    }
};
// @lc code=end

