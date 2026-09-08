// 904. 水果成篮
// 模板：不定长窗口 · 求最长（至多 k 种类型）
// 不合法条件：窗口内水果种类 > 2
// 计数技巧：0 <= fruits[i] < n，用 vector 代替 unordered_map，再用 kinds 变量维护"种类数"，
//           避免每次都算 cnt.size()（同族：159 至多 2 种、340 至多 k 种）

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        vector<int> cnt(n + 1, 0);
        int left = 0, kinds = 0, ans = 0;
        for (int right = 0; right < n; right++) {
            if (cnt[fruits[right]]++ == 0) kinds++;      // 入：出现新种类
            while (kinds > 2) {                          // 出：种类超标
                if (--cnt[fruits[left++]] == 0) kinds--;
            }
            ans = max(ans, right - left + 1);            // 更新
        }
        return ans;
    }
};
