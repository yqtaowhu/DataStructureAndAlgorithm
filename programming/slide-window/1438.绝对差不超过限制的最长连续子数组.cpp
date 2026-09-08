// 1438. 绝对差不超过限制的最长连续子数组
// 模板：不定长窗口 · 求最长 + 单调队列维护窗口内的最大/最小值
// 不合法条件：窗口最大值 - 最小值 > limit
// 队列存下标：mx 内 nums 递减（队首最大），mn 内 nums 递增（队首最小）
// 同族：239 滑动窗口最大值（定长版）、862 和至少为 K 的最短子数组

class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        deque<int> mx, mn;
        int left = 0, ans = 0;
        for (int right = 0; right < (int)nums.size(); right++) {
            while (!mx.empty() && nums[mx.back()] <= nums[right]) mx.pop_back();
            while (!mn.empty() && nums[mn.back()] >= nums[right]) mn.pop_back();
            mx.push_back(right);                          // 入：维护单调性
            mn.push_back(right);
            while (nums[mx.front()] - nums[mn.front()] > limit) {  // 出：极差超标
                if (mx.front() == left) mx.pop_front();
                if (mn.front() == left) mn.pop_front();
                left++;
            }
            ans = max(ans, right - left + 1);             // 更新
        }
        return ans;
    }
};
