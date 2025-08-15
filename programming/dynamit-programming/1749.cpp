class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        // 两次dp结果
        int ans = 0, f_max = 0, f_min = 0;
        for(int i = 0; i < nums.size(); i++) {
            f_max = max(f_max + nums[i], nums[i]);
            f_min = min(f_min + nums[i], nums[i]);
            ans = max(ans, max(f_max, -f_min));
        }
        return ans;
    }
};