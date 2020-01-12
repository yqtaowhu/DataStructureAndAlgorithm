/*
 * @lc app=leetcode.cn id=7 lang=cpp
 *
 * [7] 整数反转
 */

// @lc code=start
class Solution {
public:
    /*
    此题非常重要，虽然思路很简单
    1. 因为int型整数逆序后可能会溢出，所以我们要用long long记录中间结果；
    2. 在C++中，负数的取模运算和数学意义上的取模运算不同，结果还是负数，
        比如 −12%10=−2−12%10=−2，所以我们不需要对负数进行额外处理。
    */
    int reverse(int x) {
        long long res = 0;
        while(x) {
            res = res*10 + x%10;
            x /= 10;
        }
        return (res<INT_MIN || res>INT_MAX) ? 0 : res;
    }
};
// @lc code=end

