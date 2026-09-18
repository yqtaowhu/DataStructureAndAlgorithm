/*
 * @lc app=leetcode.cn id=693 lang=cpp
 *
 * [693] 交替位二进制数
 */

// @lc code=start
class Solution {
public:
    // 核心：若 n 的相邻两位总是不同，则 n ^ (n >> 1) 会把"每一位与它的下一位"比较，
    // 不同得 1，于是结果必是"全 1"（形如 111...1）。
    // 判断全 1：x & (x + 1) == 0（全 1 加 1 后进位成 1000...0，与自身相与为 0）。
    // 注意：n = 0x55555555 时 x = 2^31-1，x + 1 会撑爆 signed int，故用 long。
    bool hasAlternatingBits(int n) {
        long x = (long)n ^ (n >> 1);
        return (x & (x + 1)) == 0;
    }

    // 写法二：逐位比较相邻两位，出现相同即不交替（最直白，无溢出顾虑）
    bool hasAlternatingBits_2(int n) {
        int prev = n & 1;
        n >>= 1;
        while (n) {
            int cur = n & 1;
            if (cur == prev) return false;   // 相邻两位相同 → 不满足交替
            prev = cur;
            n >>= 1;
        }
        return true;
    }
};
// @lc code=end
