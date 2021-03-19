/*
 * @lc app=leetcode.cn id=300 lang=cpp
 *
 * [300] 最长上升子序列
 */

// @lc code=start
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if (n ==0) return 0;
        vector<int> res;res.push_back(nums[0]);
        for (int i=1;i<n;i++) {
            if (nums[i]>res.back()) res.push_back(nums[i]);
            else {
                int low=0,high=res.size()-1;
                while (low<=high) {
                    int mid=low+(high-low)/2;
                    if (res[mid]<nums[i]) low=mid+1;
                    else high=mid-1;
                }
                res[low]=nums[i];
            }
        }
        return res.size();   
        /*
        // 动态规划， dp[i] 为考虑前 ii 个元素，以第 ii 个数字结尾的最长上升子序列的长度
        // [10,9,2,5,3,7,101,18] dp[i] = max(dp[j]) + 1 j<i && nums[j] < nums[i]
        int n=(int)nums.size();
        if (n == 0) return 0;
        vector<int> dp(n, 0);
        for (int i = 0; i < n; ++i) {
            dp[i] = 1;
            for (int j = 0; j < i; ++j) {
                if (nums[j] < nums[i]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
        return *max_element(dp.begin(), dp.end());
        */
    }   
};
// @lc code=end

