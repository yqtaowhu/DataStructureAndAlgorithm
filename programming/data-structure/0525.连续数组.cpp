// 525. 连续数组
// https://leetcode.cn/problems/contiguous-array/
//
// 【前缀和 + 哈希表 · 模式二：最长子数组型】
// 见模板文档：./前缀和哈希表模板.md
//
// 题意：给定 0/1 数组，找最长的、0 和 1 数量相等的连续子数组，返回其长度。
//
// 关键转化：把 0 看成 -1，则「0 和 1 数量相等」<=>「子数组和为 0」。
//          子数组和为 0 <=> 两端的前缀和相等。
// 于是用哈希表记录每个前缀和「第一次出现的下标」，再次遇到同一前缀和时，
// 中间这段的和就是 0，用 i - first[s] 更新最长长度。
//
// 与计数型（560）的区别：
//   计数型 -> 哈希表存「出现次数」，累加 cnt[s-k]；
//   最长型 -> 哈希表存「首次下标」，且只在首次出现时写入（否则会变短）。

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> first; // 前缀和 -> 首次出现的下标
        first[0] = -1;                 // 空前缀：处理「从下标 0 开始」的子数组
        int s = 0, ans = 0;
        for (int i = 0; i < (int)nums.size(); i++) {
            s += (nums[i] == 1 ? 1 : -1);   // 0 当作 -1
            if (first.count(s)) {
                ans = max(ans, i - first[s]); // 相同前缀和 => 中间段和为 0
            } else {
                first[s] = i;                 // 只存最早下标，才能保证最长
            }
        }
        return ans;
    }
};
