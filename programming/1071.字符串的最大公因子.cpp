/*
 * @lc app=leetcode.cn id=1071 lang=cpp
 *
 * [1071] 字符串的最大公因子
 */

// @lc code=start
class Solution {
public:
    /*
    bool valid(string str, string s) {
        int m = str.size(), n = s.size();
        if(m % n != 0) return false;
        string tmp="";
        for(int i=1; i<= m/n; i++) {
            tmp += s;
            if(tmp != str.substr(0, i*n)) {
                return false;
            }
        }
        return true;
    }

    string gcdOfStrings(string str1, string str2) {
        if(str1.size() > str2.size()) {
            return gcdOfStrings(str2, str1);
        }
        string res = "";
        for(int i=str1.size(); i>=1; i--) {
            string s = str1.substr(0, i); // 前缀
            if(valid(str1,s) && valid(str2, s)) {
                return s;
            }
        }
        return res;
    }
    */
    string gcdOfStrings(string str1, string str2) {
        return (str1 + str2 == str2 + str1)  ?  str1.substr(0, gcd(size(str1), size(str2)))  : "";
    }
};
// @lc code=end

