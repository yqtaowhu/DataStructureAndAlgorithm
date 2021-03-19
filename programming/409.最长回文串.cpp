/*
 * @lc app=leetcode.cn id=409 lang=cpp
 *
 * [409] 最长回文串
 */

// @lc code=start
class Solution {
public:
    int longestPalindrome(string s) {
        // 总结: 只能有一个字符为奇数，其他选择偶数个
        unordered_map<char, int> count;
        int ans = 0;
        for (char c : s)
            ++count[c];
        // a = 5 
        for (auto p : count) {
            int v = p.second;
            ans += v / 2 * 2;  // ans + 4 
            if (v % 2 == 1 and ans % 2 == 0) // 第一次遇到奇数
                ++ans;
        }
        return ans;
    }
};
// @lc code=end

