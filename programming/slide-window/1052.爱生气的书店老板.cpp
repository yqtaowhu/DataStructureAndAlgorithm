// 1052. 爱生气的书店老板
// 模板：定长窗口（长度 minutes）+ 收益分离
// 拆成两部分：base = 本来就不生气分钟的顾客（与技巧无关）
//             gain = 窗口内"原本生气"的顾客（用了技巧就白赚），求其最大值
// 答案 = base + max(gain)
// 同族：2379 得到 K 个黑块的最少涂色数（同样是定长窗口数"要改的个数"）

class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = customers.size(), base = 0, gain = 0, best = 0;
        for (int i = 0; i < n; i++)
            if (grumpy[i] == 0) base += customers[i];

        for (int right = 0; right < n; right++) {
            gain += grumpy[right] ? customers[right] : 0;              // 1. 入
            if (right < minutes - 1) continue;                         // 窗口未满
            best = max(best, gain);                                    // 2. 更新
            int left = right - minutes + 1;                            // 3. 出
            gain -= grumpy[left] ? customers[left] : 0;
        }
        return base + best;
    }
};
