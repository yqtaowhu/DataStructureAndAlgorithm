/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */

// @lc code=start

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        int size = nums.size();
        sort(nums.begin(), nums.end());
        for(int i=0; i < size-2; i++) {
            if(i > 0 && nums[i] == nums[i-1]) {
                continue;
            }
            int a = nums[i], j = i+1, k = size -1;
            while(j < k) {
                int sum = a + nums[j] + nums[k];
                if(sum == 0) {
                    vector<int> v = {a, nums[j], nums[k]};
                    res.push_back(v);
                    while(j < k && nums[k] == nums[k-1]) k--;
                    k--;
                    while(j < k && nums[j] == nums[j+1]) j++;
                    j++;
                } else if(sum > 0) {
                    while(j < k && nums[k] == nums[k-1]) k--;
                    k--;
                } else {
                    while(j < k && nums[j] == nums[j+1]) j++;
                    j++;
                }
            }
        }
        return res;
    }
};
// @lc code=end

