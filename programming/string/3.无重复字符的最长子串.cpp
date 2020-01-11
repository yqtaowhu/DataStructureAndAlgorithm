/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start

/*
(双指针扫描) O(n)O(n)
定义两个指针 i,j(i<=j)i,j(i<=j)，表示当前扫描到的子串是 [i,j][i,j] (闭区间)。
扫描过程中维护一个哈希表unordered_map<char,int> hash，表示 [i,j][i,j]中每个字符出现的次数。
线性扫描时，每次循环的流程如下：

1.指针 j 向后移一位, 同时将哈希表中 s[j]的计数加一: hash[s[j]]++;
2.假设 j 移动前的区间 [i,j]中没有重复字符，则 jj 移动后，只有 s[j] 可能出现2次。因此我们不断向后移动 ii，直至区间 [i,j]中 s[j]的个数等于1为止；
复杂度分析：由于 i,j均最多增加n次，且哈希表的插入和更新操作的复杂度都是 O(1)，因此，总时间复杂度 O(n)O(n).
*/
class Solution {
public:
    // 双指针模板题
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> hash;
        int res = 0;
        for(int i=0,j=0; j<s.size(); j++) {
            hash[s[j]]++;
            while(hash[s[j]] > 1) { //只有可能是新加入的元素重复
                hash[s[i++]]--;
            }
            // [i,j]内所有元素不重复
            res = max(res, j-i+1);
        }
        return res;    
    }
};
// @lc code=end

