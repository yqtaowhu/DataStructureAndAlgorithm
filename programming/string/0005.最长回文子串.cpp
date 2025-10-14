/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */

// @lc code=start

// 暴力方法
#include<string>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int size = s.size();
        if(size <= 1) return s;
        int max_len = 0, beg = 0;
        for(int i=1; i < size; i++) {
            int j = i-1, k = i+1;
            while(j >=0 && s[j] == s[i]) {
                j--;
            }
            while(k < size && s[k] == s[i]) {
                k++;
            }
            while(j>=0 && k < size && s[j] == s[k]) {
                j--;
                k++;
            }
            if(k-j-1 > max_len) {
                beg = j + 1;
                max_len = k-j-1;
            }
        }
        return s.substr(beg, max_len);
    }
};
};
// @lc code=end

/// 动态规划方法
class Solution {
public:
    // dp[i][j] 表示 s[i, j] 是否是回文串
    // 状态转移方程：
    // dp[i][j] = s[i] == s[j] && (j - i < 3 || dp[i + 1][j - 1])
    string longestPalindrome(string s) {
        int n = s.size();
        if(n <= 1) return s;
        int max_len = 1, start = 0;
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        for(int i = 0; i < n; i++) {
            dp[i][i] = true;
        }
        for(int len = 2; len <= n; len++) {
            for(int i = 0; i < n; i++) {
                int j = i + len - 1;
                if(j >= n) break;
                if(s[i] != s[j]) {
                    dp[i][j] = false;
                } else {
                    if(j - i < 3) {
                        dp[i][j] = true;
                    } else {
                        dp[i][j] = dp[i + 1][j - 1];
                    }
                }
                if(dp[i][j] && len > max_len) {
                    max_len = len;
                    start = i;
                }
            }
        }
        return s.substr(start, max_len);
        
    }
};

