/*
 * @lc app=leetcode.cn id=44 lang=cpp
 *
 * [44] 通配符匹配
 */

// @lc code=start
class Solution {
public:
    // 动态规划dp[i][j]表示s的前i个字符是否匹配p的前j个字符
    bool isMatch(string s, string p) {
       int m=s.size(), n=p.size();
       vector<vector<bool> > dp(m+1, vector<bool>(n+1,false));
       //初始化
       dp[0][0] = true;
       for(int i=1; i<=n; i++) {
           dp[0][i] = (dp[0][i-1] && p[i-1] == '*');
       }
       for(int i=1; i<=m; i++) {
           for(int j=1; j<=n; j++) {
               // dp[i][j]可能为true的情况
               // 1. 匹配上
               if(s[i-1] == p[j-1] || p[j-1] == '?') {
                   dp[i][j] = dp[i-1][j-1];
               }
               // 2.出现*
               if(p[j-1] == '*') {
                   // a. *匹配空 dp[i][j-1]
                   // b. *匹配   dp[i-1][j]----  例如： abc 和a*的匹配方式
                   dp[i][j] = dp[i][j-1] || dp[i-1][j];
               }
           }
       }
       return dp[m][n];
    }
};
// @lc code=end

