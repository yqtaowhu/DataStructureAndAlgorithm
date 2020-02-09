/*
 * @lc app=leetcode.cn id=97 lang=cpp
 *
 * [97] 交错字符串
 */

// @lc code=start
// 尝试用回溯法去解决
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.size(), m = s2.size(), k = s3.size();
        if (k != n + m) return false;
        vector<vector<int>> f = 
            vector<vector<int>>(n + 1, vector<int>(m + 1));
        f[0][0] = 1;
        for (int i = 1; i <= n; i ++ )
            f[i][0] = f[i - 1][0] && s1[i - 1] == s3[i - 1];
        for (int i = 1; i <= m; i ++ )
            f[0][i] = f[0][i - 1] && s2[i - 1] == s3[i - 1];
        for (int i = 1; i <= n; i ++ )
            for (int j = 1; j <= m; j ++ ) {
                if (s1[i - 1] == s3[i + j - 1])
                    f[i][j] |= f[i - 1][j];
                if (s2[j - 1] == s3[i + j - 1])
                    f[i][j] |= f[i][j - 1];
            }
        return f[n][m];
    }
};
// @lc code=end

