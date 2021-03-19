#
# @lc app=leetcode.cn id=17 lang=python
#
# [17] 电话号码的字母组合
#

# @lc code=start
class Solution(object):
    def letterCombinations(self, digits):
        """
        :type digits: str
        :rtype: List[str]
        """
        phone = {'2': ['a', 'b', 'c'],
            '3': ['d', 'e', 'f'],
            '4': ['g', 'h', 'i'],
            '5': ['j', 'k', 'l'],
            '6': ['m', 'n', 'o'],
            '7': ['p', 'q', 'r', 's'],
            '8': ['t', 'u', 'v'],
            '9': ['w', 'x', 'y', 'z']}
        
        def backtrack(combination, next_digits):
            # 满足条件
            if len(next_digits) == 0:
                output.append(combination)
            # 23
            else:
                for letter in phone[next_digits[0]]:
                    # f(a,3), f(b,3),f(c,3)
                    backtrack(combination + letter, next_digits[1:])
        output = []
        if digits:
            backtrack("", digits)
        return output
        
# @lc code=end

