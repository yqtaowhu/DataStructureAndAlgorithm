/*
 * @lc app=leetcode.cn id=152 lang=cpp
 *
 * [152] 乘积最大子数组
 *
 * 模板一变种：维护"以 i 结尾"的最大/最小乘积。
 * 因为存在负数，乘一个负数会让最大变最小、最小变最大，
 * 所以遇到负数时先交换 max_f 和 min_f。
 */

// @lc code=start
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int max_s = INT_MIN;      // 全局答案
        int max_f = 1, min_f = 1; // 以当前元素结尾的最大/最小乘积
        for (const auto x : nums) {
            if (x < 0) {
                swap(max_f, min_f); // 负数翻转最大最小
            }
            max_f = max(max_f * x, x);
            min_f = min(min_f * x, x);
            max_s = max(max_s, max_f);
        }
        return max_s;
    }
};
// @lc code=end
