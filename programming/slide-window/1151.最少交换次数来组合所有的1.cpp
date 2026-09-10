// 1151. 最少交换次数来组合所有的 1
// 模板：定长窗口（入 → 更新 → 出），窗口长度 = 数组中 1 的总个数 cnt1
// 转化：把所有 1 挤到一起后，它们恰好占满一个长度为 cnt1 的窗口
//       交换次数 = 该窗口内 0 的个数（把 0 换出去、把窗外的 1 换进来），求最小值
// 与 2134 的区别：本题是普通数组（非环形），right 只走 [0, n)

class Solution {
public:
    int minSwaps(vector<int>& data) {
        int n = data.size(), cnt1 = 0;
        for (int v : data) cnt1 += v;
        if (cnt1 == 0) return 0;                   // 没有 1，无需交换
        int zeros = 0, ans = INT_MAX;
        for (int right = 0; right < n; right++) {
            zeros += data[right] == 0;             // 1. 入：统计窗口内 0
            if (right < cnt1 - 1) continue;        // 窗口未满
            ans = min(ans, zeros);                 // 2. 更新
            zeros -= data[right - cnt1 + 1] == 0;  // 3. 出
        }
        return ans;
    }
};
