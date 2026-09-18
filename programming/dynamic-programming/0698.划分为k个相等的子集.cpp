/*
 * @lc app=leetcode.cn id=698 lang=cpp
 *
 * [698] 划分为 k 个相等的子集
 *
 * 状态压缩 DP（划分型）。mask 表示"哪些元素已经被分配"。
 * dp[mask] = 在 mask 可达的前提下，当前这个"未满的组"已装入的元素之和；
 *            -1 表示该状态不可达。
 * 装满一组后和会对 target 取模归零，最终 dp[全集] == 0 说明恰好分完。
 */

// @lc code=start
class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int total = accumulate(nums.begin(), nums.end(), 0);
        if (total % k) return false;
        int target = total / k;
        if (*max_element(nums.begin(), nums.end()) > target) return false;

        int n = nums.size();
        vector<int> dp(1 << n, -1);
        dp[0] = 0; // 空集合：当前组和为 0
        for (int mask = 0; mask < (1 << n); ++mask) {
            if (dp[mask] == -1) continue; // 不可达状态跳过
            for (int i = 0; i < n; ++i) {
                if (mask & (1 << i)) continue;                 // 元素 i 已分配
                if (dp[mask] + nums[i] > target) continue;     // 超过单组容量，剪枝
                dp[mask | (1 << i)] = (dp[mask] + nums[i]) % target;
            }
        }
        return dp[(1 << n) - 1] == 0;
    }
};
// @lc code=end
