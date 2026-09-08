// 1658. 将 x 减到 0 的最小操作数
// 逆向思维：两端取走的元素和为 x ⇔ 中间保留的连续子数组和为 total - x，且要尽可能长
// 模板：不定长窗口 · 求最长（nums 全为正 ⇒ 窗口和单调 ⇒ 可以滑窗）
// 答案 = n - 最长中间窗口长度；两个边界：total < x 直接 -1，total == x 直接取全部

class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        long long total = 0;
        for (int v : nums) total += v;
        long long target = total - x;                 // 中间要保留的和
        if (target < 0) return -1;                    // 全取走也不够
        if (target == 0) return (int)nums.size();   // 正好全取走

        long long sum = 0;
        int left = 0, best = -1;
        for (int right = 0; right < (int)nums.size(); right++) {
            sum += nums[right];                       // 入
            while (sum > target) sum -= nums[left++]; // 出：和超了
            if (sum == target) best = max(best, right - left + 1);  // 更新：命中才记录
        }
        return best < 0 ? -1 : (int)nums.size() - best;
    }
};
