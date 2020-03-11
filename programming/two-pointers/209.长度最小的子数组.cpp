/*
 * @lc app=leetcode.cn id=209 lang=cpp
 *
 * [209] 长度最小的子数组
 */

// @lc code=start
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if(nums.empty()) return 0;
        int res = INT_MAX, sum = 0;
        for(int i=0, j=0; i<nums.size(); i++) {
            if(i != 0) {
                sum -= nums[i-1];
            }
            //cout<<sum<<endl;
            while(sum < s && j < nums.size()) {
                sum += nums[j++];
            }
            if(sum < s) {
                break;
            }
            res = min(j-i, res);
        }
        return res == INT_MAX ? 0: res;
    }
};
// @lc code=end

