/*
 * @lc app=leetcode.cn id=168 lang=cpp
 *
 * [168] Excel表列名称
 */

// @lc code=start
class Solution {
public:
    string convertToTitle(int n) {
        string res;
        char tmp;
        while(n){
            n -= 1;
            tmp = 'A' + n % 26;
            res = tmp + res;
            n /= 26;
        }
        return res;
    }
};
// @lc code=end

