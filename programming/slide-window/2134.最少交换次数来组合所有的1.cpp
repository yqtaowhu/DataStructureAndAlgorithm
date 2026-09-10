// 2134. 最少交换次数来组合所有的 1
// 环形数组 + 定长窗口：1 的总个数 cnt1 就是窗口长度（最终所有 1 挤在一起）
// 交换次数 = 窗口内 0 的个数（把这些 0 换到窗口外），求最小值
// 环形技巧：让 right 走 [0, 2n)，取值一律用 right % n，等价于把数组拼两遍
// 同族：1151（非环形版）、643、2379

class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size(), cnt1 = 0;
        for (int v : nums) cnt1 += v;
        if (cnt1 == 0) return 0;

        int zeros = 0, ans = INT_MAX;
        for (int right = 0; right < 2 * n; right++) {
            zeros += nums[right % n] == 0;                       // 1. 入
            if (right < cnt1 - 1) continue;                      // 窗口未满
            ans = min(ans, zeros);                               // 2. 更新
            zeros -= nums[(right - cnt1 + 1) % n] == 0;          // 3. 出
        }
        return ans;
    }
};
