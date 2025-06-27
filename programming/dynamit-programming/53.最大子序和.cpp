class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.empty()) return 0;
        int n = nums.size();
        if(n == 1) return nums[0];
        // 动态规划
        // f[i] 是以i为结尾的最大子数组
        // f[i] = max(f[i-1] + nums[i], nums[i])
        // 因为i至于i-1有关，可以优化空间复杂度
        int pre = 0, res = nums[0];
        for(const auto &x : nums) {
            pre = max(pre + x, x);
            res = max(res, pre);
        }
        return res;   
    }
};