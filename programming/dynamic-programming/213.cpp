class Solution {
public:
    int help(vector<int>& nums, int start, int end) {
        int f0 = 0, f1 = 0;
        for(int i=start; i<end; i++) {
            int x = max(f1, f0 + nums[i]);
            f0 = f1;
            f1 = x;
        }
        return f1;

    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        // 取第一个，后续从i=2开始到n-1 
        // 不取第一个, 从i=1开始到n
        return max(nums[0] + help(nums, 2, n-1), help(nums, 1, n));
        
    }
};