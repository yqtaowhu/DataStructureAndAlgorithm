// 1590. 使数组和能被 P 整除
// https://leetcode.cn/problems/make-sum-divisible-by-p/
//
// 【前缀和 + 哈希表 · 模式二：最短子数组型（带取模）】
// 见模板文档：./前缀和哈希表模板.md
//
// 题意：删除最短的连续子数组（可以为空），使剩下元素之和能被 p 整除；
//      返回删除的长度，不可能则返回 -1。（剩下部分必须非空）
//
// 关键转化：设 target = sum(nums) % p。
//   - target == 0：无需删除，返回 0；
//   - 否则要删除的子数组和 del 必须满足 del % p == target。
//     而 del = preSum[i] - preSum[j]，条件变为
//       (preSum[i] - preSum[j]) % p == target
//     => preSum[j] % p == (preSum[i] % p - target + p) % p
//   即：枚举右端点 i，查找历史上前缀余数等于 need 的最近位置 j。
// 因为要「最短」，哈希表存每个前缀余数「最近一次出现的下标」（后写覆盖前写）。
//
// 与 560 的对照：560 存「次数」求计数；本题存「最近下标」求最短长度。
// 溢出提示：nums[i] <= 1e9、n <= 1e5，累加和可达 1e14，必须用 long long。

class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        long long total = 0;
        for (int x : nums) total += x;
        int target = total % p;          // 需要删除的子数组和 mod p
        if (target == 0) return 0;       // 已经整除，删空子数组即可

        unordered_map<int, int> last;    // 前缀余数 -> 最近出现的下标
        last[0] = -1;                    // 空前缀
        long long s = 0;
        int n = nums.size(), ans = n;    // ans 初值 n 作哨兵：等于 n 说明只能删整个数组，非法
        for (int i = 0; i < n; i++) {
            s += nums[i];
            int cur = s % p;
            int need = (cur - target) % p; // 要找的历史前缀余数
            if (need < 0) need += p;       // C++ 负数取模纠正到 [0, p)
            if (last.count(need)) {
                ans = min(ans, i - last[need]);
            }
            last[cur] = i;                 // 存最近下标，才能保证最短
        }
        return ans == n ? -1 : ans;
    }
};
