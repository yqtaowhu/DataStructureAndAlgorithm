class Solution {
public:

    // f[i][j] = f[i-1][j] || f[i-1][j-nums[i]]
    // f[i+1][j] = f[i][j] || f[i][j-nums[i]]
    // f[j] = f[j] || f[j-nums[i]]
    bool canPartition(vector<int>& nums) {
        int s = reduce(nums.begin(), nums.end(), 0);
        if(s%2) return false;
        s /= 2;
        vector<bool> f(s +1, 0);
        f[0] = true;
        // 遍历nums
        for(auto num : nums) {
            // 遍历target
            for(int j = s; j >= num; --j) {
                f[j] = f[j] || f[j-num];
            }
        }
        return f[s];
    }
};