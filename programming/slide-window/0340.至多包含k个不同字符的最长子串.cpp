// 340. 至多包含 K 个不同字符的最长子串（会员题）
// 模板：不定长窗口 · 求最长（至多 k 种类型）
// 不合法条件：窗口内不同字符的种类 > k
// 计数技巧：同 159，用 int cnt[256] + kinds 增量维护种类数
//           下标须写 (unsigned char)s[i]，且数组开 256（而非 128），两者必须成对：
//           char 默认有符号 → 不转型得负下标静默算错；转型后值域 0~255 → 128 会越界
//           （详解见 0003.无重复字符的最长子串.cpp 的注释）
// 边界：k == 0 时窗口被收缩为空，此时 right - left + 1 == 0，ans 保持 0，无需特判
// 同族：159（k = 2）、3（k = 1）、904（数组版 k = 2）、992（恰好 k 种，用 atMost(k) - atMost(k-1)）

class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        int cnt[256] = {0};                            // 256：覆盖 unsigned char 全值域
        int left = 0, kinds = 0, ans = 0;
        for (int right = 0; right < (int)s.size(); right++) {
            if (cnt[(unsigned char)s[right]]++ == 0) kinds++;   // 入：出现新种类
            while (kinds > k) {                                 // 出：种类超标
                if (--cnt[(unsigned char)s[left++]] == 0) kinds--;
            }
            ans = max(ans, right - left + 1);                   // 更新
        }
        return ans;
    }
};

// Follow-up：若字符集不固定（如 Unicode），把计数数组换成哈希表
//   unordered_map<char, int> cnt;
//   while (cnt.size() > k) {
//       if (--cnt[s[left]] == 0) cnt.erase(s[left]);  // 必须 erase(key)，否则 size 不下降 → left 越界
//       left++;
//   }
