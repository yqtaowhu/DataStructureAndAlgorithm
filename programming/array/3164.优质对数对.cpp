class Solution {
public:
    int numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        // 要求: a[i] = c * k * b[j], c = 1,2,3...
        // 统计k*b[j]的倍数
        unordered_map<int, int> hash1, hash2;
        int res = 0, max_res = 0;
        for(auto n:nums1) {
            hash1[n]++;
            max_res = max(max_res, n);
        }
        for(auto n:nums2) {
            hash2[n]++;
        }
        for(auto num : hash2) {
            int n = num.first, cnt = num.second;
            // 倍数的写法要注意
            for(int b=k*n; b <= max_res ; b+=n*k) {
                if (hash1.count(b) > 0) {
                    res +=  hash1[b] * cnt;
                }
            }
        }
        return res;
    }
};