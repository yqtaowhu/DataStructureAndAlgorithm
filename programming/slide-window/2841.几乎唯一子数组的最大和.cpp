// 2841. 几乎唯一子数组的最大和
// 模板：定长窗口（入 → 更新 → 出），窗口长度 = k
// "几乎唯一" = 窗口内至少有 m 个不同元素 ⇒ 判据落在 cnt.size() >= m
// 求所有满足条件的定长窗口的最大和；一个都没有时返回 0
// 坑：① nums[i] 可达 10^9、窗口和可达 10^14 ⇒ 用 unordered_map 计数 + long long 求和
//     ② 判据落在 size()，出窗时计数减到 0 必须 erase，否则 size 会虚高

class Solution {
public:
    long long maxSum(vector<int>& nums, int m, int k) {
        int n = nums.size();
        unordered_map<int, int> cnt;               // 元素值域大，用哈希表计数
        long long sum = 0, ans = 0;
        for (int right = 0; right < n; right++) {
            sum += nums[right];                    // 1. 入
            cnt[nums[right]]++;
            if (right < k - 1) continue;           // 窗口未满
            if ((int)cnt.size() >= m) ans = max(ans, sum);   // 2. 更新：至少 m 种
            int out = nums[right - k + 1];         // 3. 出
            sum -= out;
            if (--cnt[out] == 0) cnt.erase(out);
        }
        return ans;
    }
};
