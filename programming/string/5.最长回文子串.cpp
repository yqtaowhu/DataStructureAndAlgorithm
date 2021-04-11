/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */

// @lc code=start

// 暴力方法
class Solution {
public:
    bool help(string s) {
        int i = 0, j = s.size() - 1;
        while(i < j) {
            if(s[i] != s[j]) {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    string longestPalindrome(string s) {
        int size = s.size();
        if(size <= 1) {
            return s;
        }
        int start = 0, max_len = 1;
        //cout << s.substr(0, 1) << endl;
        for(int i=0; i < size; i++) {
            for(int j=i+1; j < size; j++) {
                if(j-i+1 > max_len && help(s.substr(i, j- i + 1))) {
                    start = i;
                    max_len = j - i + 1;
                }
            }
        }
        return s.substr(start, max_len);
    }
};

// 中心扩展法   
class Solution {
public:
    string longestPalindrome(string s) {
        int size = s.size();
        if(size <= 1) {
            return s;
        }
        int start=0, max_len=1;
        for(int i=0; i < size - max_len / 2;) {
            int j = i, k = i;
            // 扩展相同字符
            while(k < size - 1 && s[k] == s[k+1]) {
                k++;
            }
            i = k+1;
            while(j > 0 && k < size -1 && s[j-1] == s[k+1]) {
                k++;
                j--;
            }
            if(k-j+1 > max_len) {
                max_len = k-j+1;
                start = j;
            }
        }
        return s.substr(start, max_len);
    }
};
// @lc code=end

