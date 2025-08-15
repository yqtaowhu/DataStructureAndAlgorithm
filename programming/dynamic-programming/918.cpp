class Solution {
public:
    // 1.最大子数组在中间 最大子数组和 max_s
    // 2.最大子数组跨两边 sum - min_s
    // 3. min_s == sum, 返回max_s
    int maxSubarraySumCircular(vector<int>& nums) {
        int max_s = INT_MIN;
        int min_s = 0;
        int max_f = 0, min_f = 0, sum = 0;
        for(auto x : nums) {
            // 以x结尾的最大子数组和
            max_f = max(x, max_f + x);
            // 以x结尾的最小子数组和
            min_f = min(x, min_f + x);
            max_s = max(max_s, max_f);
            min_s = min(min_s, min_f);
            sum += x;
        }
        return sum == min_s ? max_s : max(max_s, sum - min_s);
        
    }
};