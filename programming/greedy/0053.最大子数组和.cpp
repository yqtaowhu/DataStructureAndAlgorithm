/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子数组和
 */

// @lc code=start
class Solution {
public:
    // 贪心（Kadane）：cur 表示以当前元素结尾的最大子数组和。
    // 若前缀 cur 为负，则它对后续只有拖累，果断丢弃、从当前元素重新起算。
    int maxSubArray(vector<int>& nums) {
        int cur = nums[0], best = nums[0];
        for (int i = 1; i < (int)nums.size(); i++) {
            cur = max(nums[i], cur + nums[i]); // 要么接上前面，要么自己新开
            best = max(best, cur);
        }
        return best;
    }
};
// @lc code=end
