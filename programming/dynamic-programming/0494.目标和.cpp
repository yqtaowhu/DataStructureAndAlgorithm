class Solution {
public:
    // 设正数和p , 负数和q  
    // p + q = s
    // p - q = target
    // p = (s + target) / 2  
    // q = (s - target) / 2
    // target > 0  q小, target < 0  p小
    // m = (s-abs(target)) / 2
    // dp[i][j] : 表示前i个数字中, 和为j的方案数
    // dp[i][j] = dp[i-1][j] + dp[i-1][j-nums[i]]
    // dp[j] = dp[j] + dp[j-nums[i]]
    // 01背包组合问题
    int findTargetSumWays(vector<int>& nums, int target) {
        int s = reduce(nums.begin(), nums.end(), 0) - abs(target);
        if(s < 0 || s % 2 == 1) return 0;
        int m = s / 2;
        vector<int> dp(m+1, 0);
        dp[0] = 1; // 前0的数字， 合为0的方案数是1
        // 遍历nums
        for(auto num : nums) {
            for(int i = m; i >= num; i--) {
                dp[i] = dp[i] + dp[i-num];
            }
        }
        return dp[m];
    }
};