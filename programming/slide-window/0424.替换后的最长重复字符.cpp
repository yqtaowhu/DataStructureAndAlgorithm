// 424. 替换后的最长重复字符
// 模板：不定长窗口 · 求最长（入 → 收缩 → 更新）
// 转化：窗口里「除最高频字符之外的字符」全都要被替换 ⇒ 不合法条件：窗口长度 - maxCnt > k
// 同族：1004 / 1493 / 2024 / 2958 / 3090（本质都是「窗口内杂色个数 ≤ k」）

// ===================== 解法一：maxCnt 只增不减（推荐，O(n)） =====================
// maxCnt 存的是「历史上某个字符在某个窗口里达到过的最大出现次数」，不是当前窗口的真实值。
// 收缩之后它确实会「虚高」，让窗口虚胖甚至技术上不合法，但答案依然正确，理由有四条：
//   ① 不变量：maxCnt ≥ 当前窗口内任意字符的真实次数
//      （每个 cnt[x] 每次 +1 都会拿去刷新 maxCnt，而 maxCnt 从不减少）
//      ⇒ 判据 len - maxCnt 比真实的 len - 真实maxFreq 更小 ⇒ 收缩得更少 ⇒ 窗口「虚胖」
//   ② 窗口长度单调不减，且只在 maxCnt 被刷新时才 +1：
//      · right++ 且 maxCnt 也 +1 → len - maxCnt 不变 → 不收缩 → len 真的长了 1
//      · right++ 但 maxCnt 没变 → len - maxCnt 大了 1 → left 跟着走 1 步 → len 原地不动
//   ③ 由 ②，ans 被刷新的那一刻 maxCnt 刚被 cnt[新字符] 刷新，是真实计数，
//      再由 ① 它同时也是真实最大值 ⇒ 那一刻窗口货真价实合法，记下的每个长度都真实可达；
//      maxCnt 不刷新时 len 原地踏步，虚胖的窗口只是「陪跑」，抬不高 ans
//   ④ 上界不虚：len ≤ maxCnt + k，而 maxCnt = M 曾在某个窗口真实出现过，
//      把含这 M 个同字符的区间向外补到长度 M + k，其余 ≤ k 个字符替换掉即可 ⇒ 上界可达
// 类比：maxCnt + k 是跳高横杆，只在有人真实跳出新高时才升高，从不降低。
// 例：s = "AAABBB", k = 1，right = 4 时窗口 "AABB" 真实最高频只有 2，maxCnt 仍是 3，
//     窗口虚胖（其实要替换 2 次），但 len = 4 没超过此前真实合法的 "AAAB"，ans 不受影响。
// 结论：减小 maxCnt 只会让窗口缩得更短，而更短的窗口对「求最长」毫无帮助 ⇒ 无需回退。

class Solution {
public:
    int characterReplacement(string s, int k) {
        int cnt[26] = {0};                    // cnt[c]：当前窗口内字符 c 的出现次数
        int left = 0, maxCnt = 0, ans = 0;    // maxCnt：历史最高频次，只增不减
        for (int right = 0; right < (int)s.size(); right++) {
            // 入：新字符计数 +1，顺带尝试刷新「历史最高频次」
            maxCnt = max(maxCnt, ++cnt[s[right] - 'A']);
            // 出：需要替换的字符数 = 窗口长度 - maxCnt，超过 k 就从左边吐一个
            while (right - left + 1 - maxCnt > k) {
                cnt[s[left++] - 'A']--;       // 注意：这里故意不回退 maxCnt，理由见文件头 ①~④
            }
            // 更新：len 只可能在 maxCnt 刚被刷新时增长，那一刻窗口是真实合法的
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};

// ===================== 解法二：每步精确重算 maxCnt（maxCnt 会随收缩而缩小） =====================
// 思路：不吃「历史最大值」这个红利，每次判定前都扫一遍 26 个计数，拿当前窗口的真实最高频次。
// 与解法一的差别：
//   · 窗口在任何时刻都严格合法（判据用真实值），不存在「虚胖」
//   · left 缩得更多：还是 s = "AAABBB", k = 1，right = 4 时解法一停在 "AABB"(len 4)，
//     解法二会一路缩到 "ABB"(len 3)
//   · 最终 ans 与解法一完全相同，代价是每步多一次 O(26) 扫描 ⇒ O(26n)
// 延伸：也可枚举 26 个目标字符 c，把问题变成「窗口内非 c 的个数 ≤ k」（即 1004 模型），
//       彻底不需要 maxCnt，复杂度同为 O(26n)。
class Solution2 {
public:
    int characterReplacement(string s, int k) {
        int cnt[26] = {0};
        int left = 0, ans = 0;
        for (int right = 0; right < (int)s.size(); right++) {
            cnt[s[right] - 'A']++;                            // 入
            // 出：判据里的 maxCnt 每轮重算，收缩时会真实变小
            while (right - left + 1 - maxFreq(cnt) > k) {
                cnt[s[left++] - 'A']--;
            }
            ans = max(ans, right - left + 1);                 // 更新：此时窗口严格合法
        }
        return ans;
    }

private:
    // 当前窗口内的真实最高频次：扫一遍 26 个计数
    int maxFreq(int cnt[]) {
        int res = 0;
        for (int i = 0; i < 26; i++) {
            res = max(res, cnt[i]);
        }
        return res;
    }
};
