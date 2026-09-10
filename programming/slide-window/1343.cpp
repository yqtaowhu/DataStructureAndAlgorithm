// 1343. 大小为 K 且平均值 ≥ 阈值的子数组数目
// 模板：定长窗口（入 → 更新 → 出）
// 转化：平均值 ≥ threshold ⇔ 窗口和 ≥ threshold * k（先乘 k 免除法，避免浮点误差）
// 逐个定长窗口统计满足条件的个数
// 坑：threshold*k 与窗口和均可达 10^9 量级，用 long long

class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        long long target = 1LL * threshold * k, sum = 0;   // 阈值 ×k 免除法
        int ans = 0;
        for (int right = 0; right < (int)arr.size(); right++) {
            sum += arr[right];                     // 1. 入
            if (right < k - 1) continue;           // 窗口未满
            if (sum >= target) ans++;              // 2. 更新：计数
            sum -= arr[right - k + 1];             // 3. 出
        }
        return ans;
    }
};
