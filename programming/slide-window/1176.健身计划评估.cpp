// 1176. 健身计划评估
// 模板：定长窗口（入 → 更新 → 出），窗口长度 = k 天
// 对每个连续 k 天的卡路里总和 T 打分：T < lower 扣 1 分，T > upper 加 1 分，否则 0 分
// 返回所有窗口的累计得分（可能为负）
// 坑：k 天卡路里之和可达 2×10^9，用 long long 防溢出

class Solution {
public:
    int dietPlanPerformance(vector<int>& calories, int k, int lower, int upper) {
        long long sum = 0;
        int ans = 0;
        for (int right = 0; right < (int)calories.size(); right++) {
            sum += calories[right];                // 1. 入
            if (right < k - 1) continue;           // 窗口未满
            if (sum < lower) ans--;                // 2. 更新：按总和打分
            else if (sum > upper) ans++;
            sum -= calories[right - k + 1];        // 3. 出
        }
        return ans;
    }
};
