/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0003.无重复字符的最长子串.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taoyanqi <taoyanqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 17:29:23 by taoyanqi          #+#    #+#             */
/*   Updated: 2025/10/14 17:29:26 by taoyanqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start

/*
(滑动窗口 · 不定长求最长) O(n)
模板一：入 → 收缩 → 更新。本题判据是"每个字符出现次数 ≤ 1"，与 2958（≤ k 次）同族。
注意它与 904 / 159 / 340 **不是同一族**：那三题限制的是"种类数 ≤ k"。
  → 种类数判据落在容器上（cnt.size()），而 value 减到 0 时 key 仍存在，size 不会下降，
    所以哈希表版必须显式 erase(key)，否则 while 恒真 → left 越界
  → 本题判据落在单个 value 上（cnt[s[j]] > 1），残留的 0 计数条目不参与判断，无需 erase
  （若把本题换成 kinds 写法：while (j - i + 1 > kinds) 收缩，则与 904 完全同构）

1.右指针 j 入窗：cnt[s[j]]++
2.不合法条件：cnt[s[j]] > 1。因为入窗前 [i, j-1] 无重复，所以只有新加入的
  s[j] 可能重复，无需检查窗口内其它字符
3.收缩：i 右移并 cnt[s[i++]]--，直至 cnt[s[j]] == 1
4.窗口合法后再更新答案（求最长必须在 while 之后）：res = max(res, j - i + 1)

计数容器用 int cnt[256] 代替 unordered_map<char,int>：省掉哈希开销、空间降为 O(1)，
也避开"忘记 erase 导致 size 不下降"的坑。下面两个细节必须成对出现：
  1) 下标写 (unsigned char)s[j]：macOS/clang 下 char 默认有符号，0xC3 这类字节会被
     读成 -61，直接当下标会触发 -Wchar-subscripts 告警，且负下标会静默写到数组之前
     的栈内存（ASan 未必抓得到，答案直接算错）
  2) 数组开 256 而不是 128：转成 unsigned char 后值域是 0~255，若只开 128，遇到
     非 ASCII 字节（如 UTF-8 中文）会向高地址越界。本题保证 ASCII，但模板代码
     按 256 写才对任意输入安全，代价只是 1KB 栈空间，仍是 O(1)

复杂度分析：i、j 均最多前进 n 次，数组读写 O(1)，总时间 O(n)，空间 O(1)。
*/
class Solution {
public:
    // 滑动窗口模板题（计数数组版，不用 hash）
    int lengthOfLongestSubstring(string s) {
        int cnt[256] = {0};                            // 256：覆盖 unsigned char 全值域
        int i = 0, res = 0;
        for (int j = 0; j < (int)s.size(); j++) {
            cnt[(unsigned char)s[j]]++;                 // 入
            while (cnt[(unsigned char)s[j]] > 1) {      // 出：只有新字符可能重复
                cnt[(unsigned char)s[i++]]--;
            }
            res = max(res, j - i + 1);                  // 更新：[i,j] 内无重复
        }
        return res;
    }
};
// @lc code=end



class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // pwwkew  p 1 w 1 w 2
        int res = 0, beg = 0;
        unordered_map<char, int> map;

        for(int i=0; i < s.size(); i++) {
            map[s[i]]++;
            // s[i]有重复，一直缩短做边界
            while(map[s[i]] > 1) {
                map[s[beg++]]--;
            }
            res = max(res, i - beg + 1);
        }
        return res;
    }
};
