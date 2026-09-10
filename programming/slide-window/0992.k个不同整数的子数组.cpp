// 992. K 个不同整数的子数组
// 模板：恰好型 → 拆成「至多」相减：exactly(k) = atMost(k) - atMost(k - 1)
// atMost 内部就是计数型滑窗（每轮 += right - left + 1，即以 right 结尾的合法子数组数）
// 计数用 vector 代替 unordered_map：1 <= nums[i] <= n
// 同族：930 和相同的二元子数组、1248 统计「优美子数组」、713、1358

class Solution {
public:
    // 不同整数个数至多为 k 的子数组数目
    int atMostK(vector<int>& nums, int k) {
        if (k < 0) return 0;
        int n = nums.size();
        vector<int> cnt(n + 1, 0);
        int left = 0, kinds = 0, res = 0;
        for (int right = 0; right < n; right++) {
            if (cnt[nums[right]]++ == 0) kinds++;        // 入：新种类
            while (kinds > k) {                          // 出：种类超标
                if (--cnt[nums[left++]] == 0) kinds--;
            }
            res += right - left + 1;                     // 更新：以 right 结尾的合法子数组数
        }
        return res;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMostK(nums, k) - atMostK(nums, k - 1);
    }
};
