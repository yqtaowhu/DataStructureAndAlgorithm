/*
 * @lc app=leetcode.cn id=191 lang=cpp
 *
 * [191] 位1的个数
 */

// @lc code=start
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int res = 0;
        while(n) {
            res++;
            n &= (n-1);  // 通过n&(n-1),直接消除最右边的1
        }
        return res;
    }
    /*
    常规做法，统计每一位中是否为1
    int hammingWeight(uint32_t n) {
        int res = 0;
        while(n) {
            if(n & 1) {
                res += 1;
            }
            n = n >> 1;
        }
        return res;
    }
    /*
};
// @lc code=end

