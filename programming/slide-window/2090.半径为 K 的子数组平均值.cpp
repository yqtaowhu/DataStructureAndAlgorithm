// 2090. 半径为 K 的子数组平均值
// 模板：定长窗口（入 → 更新 → 出），窗口长度 win = 2k+1
// 中心 i 的答案是 [i-k, i+k] 的平均值（向下取整）；两端不足 k 个的位置保持 -1
// 技巧：right 是窗口右端时，中心恰为 right-k；ans 默认 -1，窗口能放下时才覆盖对应中心
// 坑：窗口和可达 10^9 量级，用 long long

class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size(), win = 2 * k + 1;
        vector<int> ans(n, -1);                    // 默认 -1（放不下窗口的位置）
        long long sum = 0;
        for (int right = 0; right < n; right++) {
            sum += nums[right];                    // 1. 入
            if (right < win - 1) continue;         // 窗口未满
            ans[right - k] = sum / win;            // 2. 更新：中心 = right-k
            sum -= nums[right - win + 1];          // 3. 出
        }
        return ans;
    }
};
