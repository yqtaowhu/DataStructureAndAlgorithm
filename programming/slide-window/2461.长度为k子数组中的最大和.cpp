// 2461. 长度为 K 子数组中的最大和
// 模板：定长窗口（入 → 更新 → 出）+ 去重判定
// 合法条件：窗口内 k 个元素互不相同 ⇒ cnt.size() == k（有重复时 size < k）
// 两个坑：① 元素可为负，ans 初值必须是 LLONG_MIN 而不是 0；② 一个合法窗口都没有时返回 0

class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> cnt;                 // 元素可为负，用哈希表计数
        long long sum = 0, ans = LLONG_MIN;
        for (int right = 0; right < n; right++) {
            sum += nums[right];                      // 1. 入
            cnt[nums[right]]++;
            if (right < k - 1) continue;             // 窗口未满
            if ((int)cnt.size() == k) ans = max(ans, sum);   // 2. 更新：恰好 k 种即互不相同
            int out = nums[right - k + 1];           // 3. 出
            sum -= out;
            if (--cnt[out] == 0) cnt.erase(out);
        }
        return ans == LLONG_MIN ? 0 : ans;
    }
};
