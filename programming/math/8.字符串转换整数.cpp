/*
 * @lc app=leetcode.cn id=8 lang=cpp
 *
 * [8] 字符串转换整数 (atoi)
 */

// @lc code=start
class Solution {
public:
    int myAtoi(string s) {
        int size = s.size();
        if(size == 0) {
            return 0;
        }
        long long int res = 0;
        int sign = 1, i = 0;
        // 去空格
        while(i < size && s[i] == ' ') {
            i++;
        }
        // 符号
        if(i < size && (s[i] == '-'  || s[i] == '+')) {
            sign = s[i] == '+' ? 1 : -1;
            i++;
        }
        // 数字 
        while(i < size && isdigit(s[i])) {
            int tmp = s[i] - '0';
            res = 10*res + tmp;
            if(res > INT_MAX) {
                return sign == 1 ? INT_MAX : INT_MIN;
            }
            i++;
        }
        return sign*res;
    }
};
// @lc code=end

