/*
 * @lc app=leetcode.cn id=164 lang=cpp
 *
 * [164] 最大间距
 */

// @lc code=start
class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) return 0;
        auto lh= minmax_element(nums.begin(), nums.end());
        int min_value = *lh.first, max_value = *lh.second;
        if (min_value == max_value) return 0;
        vector<bool> flag(n + 1, false); //表示桶是否为空
        vector<int> bucketMin(n+1,0);
        vector<int> bucketMax(n+1,0);
        for (int i = 0; i< n; i++) {    //分配桶号，和桶的最大最小值
            int bid = static_cast<int>((nums[i] - min_value) / (max_value - min_value + 0.0)*n);  //获得桶号
            bucketMin[bid] = flag[bid] ? min(bucketMin[bid], nums[i]) : nums[i];
            bucketMax[bid] = flag[bid] ? max(bucketMax[bid], nums[i]) : nums[i];
            flag[bid] = true;
        }
        int max_result = bucketMax[0], result = 0;
        for (int i = 1; i < n + 1; i++) {
            if (flag[i]) {
                result = max(bucketMin[i] - max_result, result);
                max_result = bucketMax[i];  //每次更新桶值
            }
        }
        return result;
    }
};
// @lc code=end

