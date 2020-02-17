/*
 * @lc app=leetcode.cn id=132 lang=cpp
 *
 * [132] 分割回文串 II
 */

// @lc code=start
class Solution {
public:
    //dp[i] = min([dp[j] + 1 for j in range(i) if s[j + 1, i] 是回文])
    int minCut(string s) {
        int n = s.size();
        vector<int>f(n + 1);
        vector<vector<bool>> st(n, vector<bool>(n, false));

        for (int i = 0; i < n; i ++ )
            for (int j = i; j >= 0; j -- )
                if (i - j <= 1) st[j][i] = s[j] == s[i];
                else st[j][i] = s[j] == s[i] && st[j + 1][i - 1];

        f[0] = 0;
        for (int i = 1; i <= n; i ++ ) {
            f[i] = INT_MAX;
            for (int j = 0; j < i; j ++ )
                if (st[j][i - 1])
                    f[i] = min(f[i], f[j] + 1);
        }
        return max(0, f[n] - 1);
    }
};
// @lc code=end

