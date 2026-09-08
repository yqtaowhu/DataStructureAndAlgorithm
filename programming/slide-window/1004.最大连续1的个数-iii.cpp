// 1004. 最大连续 1 的个数 III
// 模板：不定长窗口 · 求最长
// 转化：最多把 k 个 0 翻转成 1 ⇒ 不合法条件是"窗口内 0 的个数 > k"
// 同族：1493（0 最多 1 个，答案要再减 1）、2024、424、2958、3090

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left = 0, cnt0 = 0, ans = 0;
        for (int right = 0; right < (int)nums.size(); right++) {
            cnt0 += nums[right] == 0;                    // 入
            while (cnt0 > k) {                           // 出：0 太多，收缩到重新合法
                cnt0 -= nums[left++] == 0;
            }
            ans = max(ans, right - left + 1);            // 更新
        }
        return ans;
    }
};
