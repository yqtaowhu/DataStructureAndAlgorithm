/*
 * @lc app=leetcode.cn id=231 lang=cpp
 *
 * [231] 2 的幂
 */

// @lc code=start
class Solution {
public:
    bool isPowerOfTwo(int n) {
        // 2 的幂二进制只有一个 1：n & (n-1) 恰好抹掉最低位的 1，结果必为 0
        // 注意先判 n > 0，排除 0 和负数
        return n > 0 && (n & (n - 1)) == 0;
    }

    // 写法二：lowbit 只保留最低位的 1，等于自身说明只有一个 1
    bool isPowerOfTwo_2(int n) {
        return n > 0 && (n & -n) == n;
    }

    // 写法三：常规循环，反复除以 2，出现奇数且不是 1 就不是 2 的幂
    bool isPowerOfTwo_3(int n) {
        if (n <= 0) return false;
        while (n % 2 == 0) n /= 2;
        return n == 1;
    }
};
// @lc code=end
