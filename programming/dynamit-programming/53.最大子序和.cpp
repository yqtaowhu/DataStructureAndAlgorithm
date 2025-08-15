class Solution {
public:
    // dp[i]:  以nums[i]结尾的最大子数组和
    // 单独 , nums[i] , 不单独 dp[i-1] + nums[i]
    // dp[i] = max(dp[i-1], 0) + nums[i]
    // f = max(f, 0) + nums[i]
    int maxSubArray(vector<int>& nums) {
        int ans = INT_MIN;
        int f = 0;
        for(int i = 0; i < nums.size(); i++){
            f = max(f, 0) + nums[i];
            ans = max(ans, f);
        }
        return ans;
    }
};