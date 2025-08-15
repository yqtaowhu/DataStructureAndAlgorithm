class Solution {
    int solve(vector<int>& nums1, vector<int>& nums2) {
        int s1 = 0, max_sum = 0, f = 0;
        for (int i = 0; i < nums1.size(); i++) {
            s1 += nums1[i];
            f = max(f, 0) + nums2[i] - nums1[i];
            max_sum = max(max_sum, f);
        }
        return s1 + max_sum;
    }

public:
    int maximumsSplicedArray(vector<int>& nums1, vector<int>& nums2) {
        return max(solve(nums1, nums2), solve(nums2, nums1));
    }
};