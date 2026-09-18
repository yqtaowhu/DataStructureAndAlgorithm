class Solution {
public:
    // dp[i] 0-i是不是有效的划分
    // nums[i] == nums[i-1] && dp[i-2]
    // nums[i] == nums[i-1] + 1 && nums[i] == nums[i-2] + 2 && dp[i-3] 
    // nums[i] == nums[i-1] == nums[i-2] + 1 && dp[i-3] 

    bool valid(int num1, int num2, int num3) {
        return (num1 == num2 && num2 == num3) ||
               (num1 + 1== num2 && num2 +1 == num3);
    }
    bool validPartition(vector<int>& nums) {
        int n = nums.size();
        vector<bool> dp(n+1, 0);
        dp[0] = true;
        for(int i=1; i <=n ; i++) {
            if(i >= 2) {
                dp[i] = dp[i-2] && nums[i-2] == nums[i-1];
            }
            if(i >= 3) {
                dp[i] = dp[i] || (dp[i-3] && valid(nums[i-3], nums[i-2], nums[i-1]));
            }
        }
        return dp[n];
        
    }
};