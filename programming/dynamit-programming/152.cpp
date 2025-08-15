class Solution {
public:
    // 和最大子数组类似，但是因为有负数，导致最大最小颠倒
    int maxProduct(vector<int>& nums) {
        int max_s = INT_MIN;
        int max_f = 1, min_f = 1;
        for(const auto x:nums) {
            if(x < 0) {
                swap(max_f, min_f);
            }
            max_f = max(max_f * x, x);
            min_f = min(min_f * x, x);
            max_s = max(max_s, max_f);
        }
        return max_s;
    }
};