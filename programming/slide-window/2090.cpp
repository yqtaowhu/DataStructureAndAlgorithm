class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int size = nums.size();
        vector<int> res(size, -1);
        if (size < 2*k + 1) return res;
        // 初始化窗口
        long long int sum = 0;
        for(int i=0; i < 2*k; i ++) {
            sum += nums[i];
        }
        for(int i=k; i < size - k; i++) {
            sum += nums[i+k];
            res[i] = sum / (2*k + 1);
            sum -= nums[i-k];
        }
        return res;
    }
};