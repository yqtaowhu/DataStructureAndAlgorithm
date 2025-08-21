class Solution {
public:
    // dp[i] : 以i结尾的最长子序列长度
    vector<int> get_lis_array(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1), g;
        for (int i = 0; i < n; ++i) {
            auto it = lower_bound(g.begin(), g.end(), nums[i]);
            if(it == g.end()) {
                g.push_back(nums[i]);
                dp[i] = g.size();
            } else {
                *it = nums[i];
                dp[i] = it - g.begin() + 1;
            }
        }
        return dp;
    }

    int minimumMountainRemovals(vector<int>& nums) {
        vector<int> pre = get_lis_array(nums);
        vector<int> reversed_nums(nums.rbegin(), nums.rend());
        vector<int> suf = get_lis_array(reversed_nums);
        reverse(suf.begin(), suf.end());
        int ans = 0;
        for(int i=0; i<nums.size(); i++) {
            if(pre[i] > 1 && suf[i] > 1) {
                ans = max(pre[i] + suf[i] - 1, ans);
            }
        }
        return nums.size() - ans;
    }
};