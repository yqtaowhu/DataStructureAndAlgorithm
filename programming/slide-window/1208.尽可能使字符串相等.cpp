// 1208. 尽可能使字符串相等
// 模板：不定长窗口 · 求最长（预算型：窗口内总花费 <= maxCost）
// 花费 cost[i] = |s[i] - t[i]|
// 与 209 是同一枚硬币的两面：209 是"和 >= target 求最短"，本题是"和 <= maxCost 求最长"

class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int left = 0, cost = 0, ans = 0;
        for (int right = 0; right < (int)s.size(); right++) {
            cost += abs(s[right] - t[right]);            // 入
            while (cost > maxCost) {                     // 出：预算超支
                cost -= abs(s[left] - t[left]);
                left++;
            }
            ans = max(ans, right - left + 1);            // 更新
        }
        return ans;
    }
};
