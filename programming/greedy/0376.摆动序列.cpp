/*
 * @lc app=leetcode.cn id=376 lang=cpp
 *
 * [376] 摆动序列
 */

// @lc code=start
class Solution {
public:
    // 贪心：最长摆动序列长度 == 序列中「拐点」个数 + 1。
    // 平坡（相等）不算拐点；连续同向只保留最后一个转折点。
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) return n;
        int prevDiff = 0, res = 1; // prevDiff 记录上一段的有效差值方向
        for (int i = 1; i < n; i++) {
            int diff = nums[i] - nums[i - 1];
            // 出现方向翻转（含从平坡转为有方向）时，拐点 +1
            if ((diff > 0 && prevDiff <= 0) || (diff < 0 && prevDiff >= 0)) {
                res++;
                prevDiff = diff;
            }
        }
        return res;
    }
};
// @lc code=end
