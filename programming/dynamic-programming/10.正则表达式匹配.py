#
# @lc app=leetcode.cn id=10 lang=python
#
# [10] 正则表达式匹配
#

# @lc code=start
class Solution(object):
    def isMatch(self, s, p):
        """
        :type s: str
        :type p: str
        :rtype: bool
        """
        if not p:
            return not s
        # 考虑第一个字符是否匹配
        first_match = bool(s) and p[0] in {s[0], '.'}
        # 如果第二个字符为*
        if len(p) >= 2 and p[1] == '*':
            # 未匹配，删除p前两位， 匹配则让s后移
            return (self.isMatch(s, p[2:]) or
                   (first_match and self.isMatch(s[1:], p))) 
        else:
            return first_match and self.isMatch(s[1:], p[1:])
# 动态规划的方法，用dp(i,j)表示 s[i:], p[j:]是否匹配
# 参考资料: https://leetcode-cn.com/problems/regular-expression-matching/solution/zheng-ze-biao-da-shi-pi-pei-by-leetcode/

class Solution(object):
    def isMatch(self, text, pattern):
        memo = {}
        def dp(i, j):
            if (i, j) not in memo:
                if j == len(pattern):
                    ans = i == len(text)
                else:
                    first_match = i < len(text) and pattern[j] in {text[i], '.'}
                    if j+1 < len(pattern) and pattern[j+1] == '*':
                        ans = dp(i, j+2) or first_match and dp(i+1, j)
                    else:
                        ans = first_match and dp(i+1, j+1)

                memo[i, j] = ans
            return memo[i, j]

        return dp(0, 0)
        
# @lc code=end

