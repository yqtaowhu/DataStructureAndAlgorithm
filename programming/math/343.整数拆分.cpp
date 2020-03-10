/*
 * @lc app=leetcode.cn id=343 lang=cpp
 *
 * [343] 整数拆分
 */

// @lc code=start
class Solution {
public:
    int integerBreak(int n) {
        if(n == 2) return 1;
        if(n == 3) return 2;
        int res = 0, div = n / 3, dov = n % 3;
        if(dov == 0) {
            return pow(3, div);
        } else if(dov == 1) {
            return pow(3, div-1)*4;
        } else {
            return pow(3, div)*2;
        }
    }
};
// @lc code=end

