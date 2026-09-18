class Solution {
public:
    // int rob(vector<int>& nums) {
    //     // dp[i] = max(dp[i-1], dp[i-2] + nums[i]) dp[i]: i时最大的收获
    //     if(nums.empty()) return 0;
    //     int n = nums.size();
    //     vector<int> dp(n+1, 0);
    //     dp[1] =  nums[0];
    //     for(int i=2; i <=n; i++) {
    //         dp[i] = max(dp[i-1], dp[i-2] + nums[i-1]);
    //     }
    //     return dp[n];
    // }

    // 空间优化
    int rob(vector<int>& nums) {
        // dp[i] = max(dp[i-1], dp[i-2] + nums[i]) dp[i]: i时最大的收获
        if(nums.empty()) return 0;
        int n = nums.size();
        //vector<int> dp(n+1, 0);
        //dp[1] =  nums[0];
        int f1 = nums[0], f0 = 0;
        for(int i=2; i <=n; i++) {
            //dp[i] = max(dp[i-1], dp[i-2] + nums[i-1]);
            int x = max(f1, f0 + nums[i-1]);
            f0 = f1;
            f1 = x;
        }
        return f1;
    }
};