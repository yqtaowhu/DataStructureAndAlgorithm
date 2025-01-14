class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        // 前缀和问题
        int size = nums.size();
        vector<long long int> sum(size + 1, 0);
        for (int i = 1; i <= size; i++) {
            sum[i] = sum[i - 1] + nums[i - 1];
        }
        int res = 0;
        for(int i = 1; i < size; i++) {
            if (sum[i] >= sum[size] - sum[i]) {
                res++;
            }
        }
        return res;
    }
};