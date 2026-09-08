// 2024. 考试的最大困扰度
// 模板：不定长窗口 · 求最长，跑两遍（把 'T' 当杂色 / 把 'F' 当杂色）
// 与 1004 同族：不合法条件 = 窗口内"另一种字符"的个数 > k

class Solution {
public:
    // other 视为需要修改的字符，求窗口内 other 个数 <= k 的最长长度
    int longestRun(string& s, int k, char other) {
        int left = 0, cnt = 0, ans = 0;
        for (int right = 0; right < (int)s.size(); right++) {
            cnt += s[right] == other;                    // 入
            while (cnt > k) cnt -= s[left++] == other;   // 出
            ans = max(ans, right - left + 1);            // 更新
        }
        return ans;
    }

    int maxConsecutiveAnswers(string answerKey, int k) {
        return max(longestRun(answerKey, k, 'T'), longestRun(answerKey, k, 'F'));
    }
};
