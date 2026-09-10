// 862. 和至少为 K 的最短子数组
// 普通滑窗模板在这里失效！数组含负数 ⇒ 窗口和不单调 ⇒ 无法判断"何时可以收缩"
// 正解：前缀和 + 单调队列（队列内前缀和严格递增，队首最小且最老）
// 与 209 对比记忆：209 全为正数用滑窗，862 含负数用单调队列
// 注意前缀和用 long long：n=1e5、|nums[i]|=1e5，最大可达 1e10

class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> pre(n + 1, 0);
        for (int i = 0; i < n; i++) pre[i + 1] = pre[i] + nums[i];

        deque<int> dq;                    // 存前缀和下标，pre[dq] 单调递增
        int ans = n + 1;
        for (int i = 0; i <= n; i++) {
            // 队首能与 i 组成合法窗口 ⇒ 记录后弹出（i 再往右只会更长，队首没有再用价值）
            while (!dq.empty() && pre[i] - pre[dq.front()] >= k) {
                ans = min(ans, i - dq.front());
                dq.pop_front();
            }
            // 维护单调性：前缀和比 pre[i] 大的下标，既更老又更大，永远不可能更优
            while (!dq.empty() && pre[dq.back()] >= pre[i]) dq.pop_back();
            dq.push_back(i);
        }
        return ans == n + 1 ? -1 : ans;
    }
};
