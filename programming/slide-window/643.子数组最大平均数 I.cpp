class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int size = nums.size();
        if (size < k) return 0;
        double max_sum = INT_MIN, sum = 0;
        // 初始化窗口
        for(int i=0; i < k-1; i++) {
            sum += nums[i];
        }
        for(int i=k-1; i < size; i++) {
            // insert
            sum += nums[i];
            // update
            max_sum = max(max_sum, sum);
            // delete
            sum -= nums[i-k+1];
        }
        return max_sum / k;
    }
};