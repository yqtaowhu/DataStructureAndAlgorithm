// 2379. 得到 K 个黑块的最少涂色数
// 模板：定长窗口（入 → 更新 → 出）
// 转化：想让某个长度为 k 的窗口全变黑，就要把窗口内的 'W' 全部涂黑
// 即统计每个定长窗口内 'W' 的个数，取其最小值
// 同族：1052 爱生气的书店老板（同样是定长窗口数"要改的个数"）

class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int cnt = 0, ans = INT_MAX;
        for (int right = 0; right < (int)blocks.size(); right++) {
            cnt += blocks[right] == 'W';           // 1. 入：统计窗口内 W
            if (right < k - 1) continue;           // 窗口未满
            ans = min(ans, cnt);                   // 2. 更新：求最少涂色数
            cnt -= blocks[right - k + 1] == 'W';   // 3. 出
        }
        return ans;
    }
};
