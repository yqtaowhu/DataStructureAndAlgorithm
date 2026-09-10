// 643. 子数组最大平均数 I
// 模板：定长窗口（入 → 更新 → 出）标准三步
// 求长度恰好为 k 的子数组的最大和，最后除以 k 即为最大平均数
// 坑：窗口和可达 10^9 量级，sum/ans 用 long long 防溢出，ans 初值 LLONG_MIN

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        long long sum = 0, ans = LLONG_MIN;
        for (int right = 0; right < (int)nums.size(); right++) {
            sum += nums[right];                    // 1. 入
            if (right < k - 1) continue;           // 窗口未满
            ans = max(ans, sum);                   // 2. 更新：窗口长度恰好为 k
            sum -= nums[right - k + 1];            // 3. 出
        }
        return (double)ans / k;
    }
};
