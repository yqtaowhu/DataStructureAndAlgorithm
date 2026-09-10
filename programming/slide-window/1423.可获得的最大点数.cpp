// 1423. 可获得的最大点数
// 逆向思维：只能从两端各取若干、共取 k 张 ⇒ 剩下的是中间连续 n-k 张
//           要"取到的最大" ⇔ 要"剩下的最小"
// 模板：定长窗口（长度 n-k）求最小和，答案 = total - minSum
// 同族：1658（两端取走和为 x）、2134（环形定长）

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size(), win = n - k;
        long long total = 0;
        for (int v : cardPoints) total += v;
        if (win == 0) return (int)total;              // 全取走

        long long sum = 0, minSum = total;
        for (int right = 0; right < n; right++) {
            sum += cardPoints[right];                 // 1. 入
            if (right < win - 1) continue;            // 窗口未满，先不统计
            minSum = min(minSum, sum);                // 2. 更新
            sum -= cardPoints[right - win + 1];       // 3. 出
        }
        return (int)(total - minSum);
    }
};
