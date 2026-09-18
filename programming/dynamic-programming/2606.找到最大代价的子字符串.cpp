class Solution {
public:
    int maximumCostSubstring(string s, string chars, vector<int>& vals) {
        vector<int> v(26, 0);
        for(int i=0; i < v.size(); i++) {
            v[i] = i + 1;
        }
        for(int i = 0; i < chars.size(); i++) {
            v[chars[i] - 'a'] = vals[i];
        }
        // dp[i] = max(dp[i-1], 0) + nums[i]
        int res = 0, f = 0;
        for(int i = 0; i < s.size(); i++) {
            f = max(f, 0) + v[s[i] - 'a'];
            res = max(res, f);
        }
        return res;
    }
};