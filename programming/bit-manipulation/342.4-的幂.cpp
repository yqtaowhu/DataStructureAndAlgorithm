/*
 * @lc app=leetcode.cn id=342 lang=cpp
 *
 * [342] 4 的幂
 */

// @lc code=start
class Solution {
public:
    bool isPowerOfFour(int n) {
        // 1. n > 0 排除 0 和负数
        // 2. n & (n-1) == 0 保证是 2 的幂（只有一个 1）
        // 3. n & 0x55555555 保证唯一的 1 在奇数位（第 0、2、4... 位），即 4^k
        //    0x55555555 = 0101...0101
        return n > 0 && (n & (n - 1)) == 0 && (n & 0x55555555) == n;
    }

    // 写法二：是 2 的幂，且 4^k - 1 是 3 的倍数，故 n % 3 == 1
    bool isPowerOfFour_2(int n) {
        return n > 0 && (n & (n - 1)) == 0 && n % 3 == 1;
    }

    // 写法三：循环除以 4
    bool isPowerOfFour_3(int n) {
        if (n <= 0) return false;
        while (n % 4 == 0) n /= 4;
        return n == 1;
    }
};
// @lc code=end
