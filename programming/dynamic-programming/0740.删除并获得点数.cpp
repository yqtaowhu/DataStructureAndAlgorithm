class Solution {
    // 198. 打家劫舍
    int rob(vector<int>& nums) {
        int f0 = 0, f1 = 0;
        for (int x : nums) {
            int new_f = max(f1, f0 + x);
            f0 = f1;
            f1 = new_f;
        }
        return f1;
    }

public:
    int deleteAndEarn(vector<int>& nums) {
        int mx = ranges::max(nums);
        vector<int> a(mx + 1);
        for (int x : nums) {
            a[x] += x; // 统计等于 x 的元素之和
        }
        return rob(a);
    }
};