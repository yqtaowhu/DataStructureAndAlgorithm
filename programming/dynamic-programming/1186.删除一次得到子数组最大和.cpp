class Solution {
public:
    int maximumSum(vector<int> &arr) {
        int ans = INT_MIN, n = arr.size();
        vector<vector<int>> f(n + 1, vector<int>(2, INT_MIN / 2)); // 除 2 防止负数相加溢出
        for (int i = 0; i < n; i++) {
            f[i + 1][0] = max(f[i][0], 0) + arr[i];
            f[i + 1][1] = max(f[i][1] + arr[i], f[i][0]);
            ans = max(ans, max(f[i + 1][0], f[i + 1][1]));
        }
        return ans;
    }
};