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

