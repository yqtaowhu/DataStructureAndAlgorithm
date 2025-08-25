class Solution {
public:
    // 统计状态0-i是不是回文
    // 如果dp[i]是回文直接返回0
    // 如果dp[i]不是回文，从j=1开始遍历，如果[j,i]是回文，可以进行切割，同时记录最小值
    int minCut(string s) {
        int n = s.size();
        vector<vector<bool>> st(n, vector<bool>(n, false));

        for (int i = 0; i < n; i ++ )
            for (int j = i; j >= 0; j -- )
                if (i - j <= 1) {
                    st[j][i] = s[j] == s[i];
                } else {
                    st[j][i] = s[j] == s[i] && st[j + 1][i - 1]; 
                }

        vector<int> f(n);
        for(int r=0;r<n;r++) {
            if(st[0][r])  {
                continue;
            }
            int res = INT_MAX;
            for(int l=1; l<=r; l++) {
                if(st[l][r]) {
                    res = min(res, f[l - 1] + 1);
                }
            }
            f[r] = res;
        }
        return f[n - 1];
    }
};