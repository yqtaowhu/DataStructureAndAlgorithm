/*
 * @lc app=leetcode.cn id=300 lang=cpp
 *
 * [300] 最长上升子序列
 */

// @lc code=start
class Solution {
public:
    /*
     * 贪心 + 二分查找，时间 O(n log n)，空间 O(n)。
     *
     * 核心不变量：v[k] = 所有长度为 k+1 的上升子序列中，结尾元素的最小值。
     * v 始终严格递增（二分的前提），但 v 本身不必是一条真实存在的子序列——
     * 替换操作只更新“最有潜力的结尾”，不改变长度，而答案就是 v.size()。
     *
     * 相比手写二分，直接用 lower_bound（找第一个 >= nums[i] 的位置），
     * 语义清晰且不易写错：
     *   - nums[i] > v.back()：直接追加，LIS 长度 +1；
     *   - 否则替换 v[left] = nums[i]（v[left-1] < nums[i] <= v[left]，
     *     替换后依然严格递增）。
     *
     * 额外记录前驱信息，可在 O(LIS) 时间内还原出具体序列：
     *   - idx[k]：当前 v[k] 对应的原数组下标；
     *   - pre[i]：以 nums[i] 结尾的链的前驱下标。
     *   每次设置 pre[i] = idx[left-1] 时都保证前驱下标更小、值严格更小，
     *   因此从 idx.back() 沿 pre 回溯得到的一定是一条真实的严格上升子序列。
     */
    int lengthOfLIS(vector<int>& nums) {
        vector<int> v;  // 需要保证有序, 不一定是真实存在的
        // 10,9,2,5,3,7,101,18
        for(int i=0; i < nums.size(); i++) {
            if(v.empty() || nums[i] > v.back()) {
                v.push_back(nums[i]);
            } else {
                int idx = lower_bound(v.begin(), v.end(), nums[i]) - v.begin(); // 找插入位置
                v[idx] = nums[i]; 
            }
        }
        return v.size();
    }
    // 回溯具体序列：在贪心+二分基础上额外记录前驱，时间 O(n log n)
    int lengthOfLISWithSeq(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;

        vector<int> v;          // v[k]: 长度为 k+1 的 LIS 的最小结尾值
        vector<int> idx;        // idx[k]: v[k] 对应的原数组下标
        vector<int> pre(n, -1); // pre[i]: nums[i] 所在链的前驱下标

        for (int i = 0; i < n; i++) {
            if (v.empty() || nums[i] > v.back()) {
                pre[i] = v.empty() ? -1 : idx.back();
                v.push_back(nums[i]);
                idx.push_back(i);
            } else {
                int left = lower_bound(v.begin(), v.end(), nums[i]) - v.begin();
                pre[i] = (left == 0) ? -1 : idx[left - 1]; // 先记前驱再覆盖
                v[left] = nums[i];
                idx[left] = i;
            }
        }

        // 回溯还原具体序列（LeetCode 只需要长度，这里仅演示）
        // vector<int> lis;
        // for (int i = idx.back(); i != -1; i = pre[i]) lis.push_back(nums[i]);
        // reverse(lis.begin(), lis.end());

        return v.size();
    }

    /*
     * 动态规划写法，时间 O(n^2)，空间 O(n)。
     *
     * 状态定义：dp[i] = 以 nums[i] 结尾的最长上升子序列的长度。
     * 状态转移：dp[i] = max(dp[j] + 1)，其中 0 <= j < i 且 nums[j] < nums[i]；
     *          若不存在这样的 j，则 dp[i] = 1（自身单独成链）。
     * 答案：max(dp[i])，注意不是 dp[n-1]——LIS 不一定以最后一个元素结尾。
     *
     * 对比贪心+二分：
     *   - dp 定义更直观（以 i 结尾），好想好证明，还原序列也天然简单（记 pre）；
     *   - 但转移需要枚举所有前驱 j，多一个 log 因子的代价，n 大时明显慢；
     *   - 贪心+二分难在理解不变量，一旦理解代码反而更短。
     */
    int lengthOfLIS_DP(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;

        vector<int> dp(n, 1);   // dp[i]: 以 nums[i] 结尾的 LIS 长度，初始为 1
        vector<int> pre(n, -1); // pre[i]: 以 nums[i] 结尾的链的前驱下标，用于还原序列

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i] && dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                    pre[i] = j;
                }
            }
        }

        // 还原具体序列：找到最长链的结尾，沿 pre 回溯
        // int end = max_element(dp.begin(), dp.end()) - dp.begin();
        // vector<int> lis;
        // for (int i = end; i != -1; i = pre[i]) lis.push_back(nums[i]);
        // reverse(lis.begin(), lis.end());

        return *max_element(dp.begin(), dp.end());
    }
};
// @lc code=end

