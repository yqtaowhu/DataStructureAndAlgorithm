// 长度最小的子数组
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int size = nums.size();
        int sum = 0, res = INT_MAX;
        for(int i=0, j=0; j < size; j++) {
            sum += nums[j];
            while(sum >= target) {
                res = min(j-i+1, res);
                sum -= nums[i++];
            }
        }
        return res == INT_MAX ? 0 : res;
    }
};