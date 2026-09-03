class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        // 等价于求 m,n 从低位开始，位数相同的高位（公共前缀）
        if (m == 0) return 0;          // 区间含 0，与结果必为 0（提前剪枝）
        int moveFactor = 1;            // 记录右移掉多少位，最后补回来
        while (m != n) {               // m、n 不相等，说明还有不同的低位
            m >>= 1;                   // 去掉 m 的最低位
            n >>= 1;                   // 去掉 n 的最低位
            moveFactor <<= 1;          // 右移次数 × 2（即记录 2^右移次数）
        }
        // 此时 m == n == 公共前缀，把右移掉的低位用 0 补回来
        return m * moveFactor;         // 等价于 m << (右移的位数)
    }
};