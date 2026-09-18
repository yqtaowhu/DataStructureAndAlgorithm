/*
 * @lc app=leetcode.cn id=1009 lang=cpp
 *
 * [1009] 十进制整数的反码
 */

// @lc code=start
class Solution {
public:
    // 与 476.数字的补数 完全同款：位宽内取反。
    // 唯一区别：本题 n 可以取 0，而 0 的二进制是 "0"，其反码定义为 "1"，需特判。
    // 同样注意 1 << 31 的 signed 溢出问题，掩码全程用 unsigned。
    int bitwiseComplement(int n) {
        if (n == 0) return 1;                              // 特判：0 → 1
        unsigned mask = (1u << bit_width((unsigned)n)) - 1; // 位宽内全 1
        return ~n & mask;                                  // 位宽内取反
    }

    int bit_width(unsigned n) {
        return 32 - __builtin_clz(n);   // n >= 1，O(1)
    }

    // 写法二：从全 1 掩码左移盖过最高位。n == 0 时循环不执行，靠 |(n==0) 补上那一位
    int bitwiseComplement_2(int n) {
        unsigned mask = ~0u;
        while (mask & (unsigned)n) mask <<= 1;
        return (~n & ~mask) | (n == 0);
    }
};
// @lc code=end
