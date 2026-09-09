// 159. 至多包含两个不同字符的最长子串（会员题）
// 模板：不定长窗口 · 求最长（至多 k 种类型，本题 k = 2）
// 不合法条件：窗口内不同字符的种类 > 2
// 计数技巧：用 int cnt[256] 代替 unordered_map，再用 kinds 变量增量维护"种类数"，
//           避免每轮都算 size()
//           下标写 (unsigned char)s[i] 与数组开 256（而非 128）必须成对出现：char 默认
//           有符号 → 不转型会得到负下标并静默算错；转型后值域 0~255 → 只开 128 遇非
//           ASCII 字节会越界（详解见 0003.无重复字符的最长子串.cpp 的注释）
// 同族：3（k = 1，无重复字符）、904（数组版 k = 2）、340（本题一般化 k 任意）

class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int cnt[256] = {0};                            // 256：覆盖 unsigned char 全值域
        int left = 0, kinds = 0, ans = 0;
        for (int right = 0; right < (int)s.size(); right++) {
            if (cnt[(unsigned char)s[right]]++ == 0) kinds++;   // 入：出现新种类
            while (kinds > 2) {                                 // 出：种类超标
                if (--cnt[(unsigned char)s[left++]] == 0) kinds--;
            }
            ans = max(ans, right - left + 1);                   // 更新
        }
        return ans;
    }
};
