// 523. 连续的子数组和
// https://leetcode.cn/problems/continuous-subarray-sum/
//
// 【前缀和 + 哈希表 · 模式二：存在型（带长度约束 + 取模）】
// 见模板文档：./前缀和哈希表模板.md
//
// 题意：判断是否存在长度 >= 2 的子数组，其和是 k 的倍数。
//
// 关键转化：子数组和是 k 的倍数 <=> 两端前缀和对 k 取模相等。
//          用哈希表记录每个「前缀和余数」第一次出现的下标；
//          若同一余数再次出现，且两次下标之差 >= 2（保证长度至少 2），即成立。
//
// 与 525 的区别：525 求「最长长度」，本题只求「是否存在」并多了长度 >= 2 的约束。
// 约束提示：本题 nums[i] >= 0、k >= 1，故前缀和 s >= 0，s % k 天然非负，
//          无需像 974 那样做 (x%k+k)%k 的负数纠正。

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> first; // 前缀和余数 -> 首次出现的下标
        first[0] = -1;                 // 空前缀：处理「从下标 0 开始」的子数组
        int s = 0;
        for (int i = 0; i < (int)nums.size(); i++) {
            s += nums[i];
            int r = s % k;
            if (first.count(r)) {
                if (i - first[r] >= 2) return true; // 长度至少为 2
            } else {
                first[r] = i;                       // 只存最早下标
            }
        }
        return false;
    }
};
