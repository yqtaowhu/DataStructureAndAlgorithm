class Solution {
    // 53. 最大子数组和（repeat 表示重复次数）
    int maxSubArray(vector<int>& nums, int repeat) {
        int n = nums.size();
        int ans = 0, f = 0; // 本题允许子数组为空，ans 可以初始化成 0
        for (int i = 0; i < n * repeat; i++) {
            f = max(f, 0) + nums[i % n];
            ans = max(ans, f);
        }
        return ans;
    }

public:
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        if (k == 1) {
            return maxSubArray(arr, 1);
        }
        long long ans = maxSubArray(arr, 2); // arr+arr 的最大子数组和
        int s = reduce(arr.begin(), arr.end());
        ans += 1LL * max(s, 0) * (k - 2);
        return ans % 1'000'000'007;
    }
};