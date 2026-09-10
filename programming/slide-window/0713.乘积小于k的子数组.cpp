// 713. 乘积小于 K 的子数组
// 模板：不定长窗口 · 计数型（求合法子数组的总个数）
// 计数关键：每轮累加 right - left + 1，正好是"以 right 结尾"的合法子数组个数，不重不漏
// 坑：nums[i] >= 1，当 k <= 1 时任何窗口都不合法，必须先返回 0，否则 while 里 left 越过 right

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k <= 1) return 0;
        int left = 0, ans = 0;
        long long prod = 1;                              // 用 long long 防乘积溢出
        for (int right = 0; right < (int)nums.size(); right++) {
            prod *= nums[right];                         // 入
            while (prod >= k) prod /= nums[left++];      // 出：乘积超标
            ans += right - left + 1;                     // 更新：以 right 结尾的合法子数组数
        }
        return ans;
    }
};
