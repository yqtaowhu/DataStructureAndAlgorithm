// 438. 找到字符串中所有字母异位词
// 模板：定长窗口（入 → 更新 → 出），窗口长度 = p.size()
// 异位词 ⇔ 窗口内 26 个字母的计数与 p 完全相等
// 优化：只维护一个「差值数组」cnt[c] = 窗口内计数 - p 内计数，
//       再用 diff 记录有多少个字母的差值 != 0；diff==0 即为异位词。
//       每次滑动只更新「进入」和「离开」两个字符 ⇒ 每步 O(1)，整体 O(n)
//       （对比：每步都完整比较两个 int[26] 数组是 O(26·n)，常数更大）
// 记录所有满足条件的窗口起点（right - m + 1）
// 同族：567（存在版，命中即返回）、30（按单词长度分组滑）

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.size(), m = p.size();
        vector<int> ans;
        if (n < m) return ans;

        int cnt[26] = {0};                 // cnt[c] = 窗口内计数 - p 内计数
        for (char c : p) cnt[c - 'a']--;
        int diff = 0;                      // 差值 != 0 的字母个数，diff==0 即异位词
        for (int i = 0; i < 26; i++) if (cnt[i]) diff++;

        for (int right = 0; right < n; right++) {
            int in = s[right] - 'a';       // 1. 入：s[right] 进入窗口，cnt++
            if (cnt[in] == 0) diff++;      //   0 -> 1，新增一处不匹配
            if (++cnt[in] == 0) diff--;    //   -1 -> 0，消除一处不匹配

            if (right < m - 1) continue;   // 窗口未满
            if (diff == 0) ans.push_back(right - m + 1);  // 2. 更新：O(1) 判定

            int out = s[right - m + 1] - 'a'; // 3. 出：左端字符离开窗口，cnt--
            if (cnt[out] == 0) diff++;     //   0 -> -1，新增一处不匹配
            if (--cnt[out] == 0) diff--;   //   1 -> 0，消除一处不匹配
        }
        return ans;
    }
};
