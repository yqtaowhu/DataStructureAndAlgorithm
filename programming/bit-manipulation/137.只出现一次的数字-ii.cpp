/*
 * @lc app=leetcode.cn id=137 lang=cpp
 *
 * [137] 只出现一次的数字 II
 */

// @lc code=start
class Solution {
public:
    // 通用的解法: 统计每一位出现的次数
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for (int bit = 0; bit < 32; bit++) {
            int counter = 0;
            for (int i = 0; i < nums.size(); i++)
                counter += (nums[i] >> bit) & 1;
            ans += (counter % 3) << bit;
        }
        return ans;
    }
};
// @lc code=end

