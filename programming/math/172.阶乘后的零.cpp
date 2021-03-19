/*
 * @lc app=leetcode.cn id=172 lang=cpp
 *
 * [172] 阶乘后的零
 */

// @lc code=start
class Solution {
public:
    int trailingZeroes(int n) {
        int res = 0;
        while(n) {
            res += n/5;
            n /= 5;
        }
        return res;
    }
};
// @lc code=end

