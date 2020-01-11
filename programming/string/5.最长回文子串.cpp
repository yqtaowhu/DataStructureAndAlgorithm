/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */

// @lc code=start
class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty()) return "";
        if (s.size() == 1) return s;
        int min_start = 0, max_len = 1;      //
        for (int i = 0; i < s.size();) {
            if (s.size() - i <= max_len / 2) break;
            int j = i, k = i;       //j is a pre pointer,k is next pointer
            // 特别重要，上一个扩展的i一定和此次的不同，因此要去重操作
            while (k < s.size() - 1 && s[k + 1] == s[k])
                ++k; // Skip duplicate characters.
            i = k + 1;
            while (k < s.size() - 1 && j > 0 && s[k + 1] == s[j - 1]) 
            {
                ++k; 
                --j; 
            } // Expand.
            int new_len = k - j + 1;
            if (new_len > max_len) 
            {
                min_start = j;
                max_len = new_len; 
            }
        }
        return s.substr(min_start, max_len); 
    }
};
// @lc code=end

