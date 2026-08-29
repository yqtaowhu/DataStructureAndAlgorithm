/*
 * @lc app=leetcode.cn id=470 lang=cpp
 *
 * [470] 用 Rand7() 实现 Rand10()
 */

// @lc code=start
// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
public:
    int rand10() {
        // 首先得到一个数, rand7() -> 0, 1, 2, .. 6
        // 0 ... 49  的均匀
        int num = (rand7() - 1) * 7 + rand7();
        // 只要它还大于40，那你就给我不断生成吧
        while (num > 40) {
            num = (rand7() - 1) * 7 + rand7();
        }
        // 返回结果，+1是为了解决 40%10为0的情况
        return 1 + num % 10;
    }
};
// @lc code=end

