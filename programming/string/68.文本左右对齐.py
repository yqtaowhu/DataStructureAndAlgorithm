#
# @lc app=leetcode.cn id=68 lang=python
#
# [68] 文本左右对齐
#

# @lc code=start
class Solution(object):
    # https://leetcode.com/problems/text-justification/discuss/24891/Concise-python-solution-10-lines.
    def fullJustify(self, words, maxWidth):
        """
        :type words: List[str]
        :type maxWidth: int
        :rtype: List[str]
        """
        res, cur, num_of_letters = [], [], 0
        for w in words:
            if num_of_letters + len(w) + len(cur) > maxWidth:
                for i in range(maxWidth - num_of_letters):
                    cur[i%(len(cur)-1 or 1)] += ' '
                res.append(''.join(cur))
                cur, num_of_letters = [], 0
            cur += [w]
            num_of_letters += len(w)
        return res + [' '.join(cur).ljust(maxWidth)]
        
# @lc code=end

