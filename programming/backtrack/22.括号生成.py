#
# @lc app=leetcode.cn id=22 lang=python
#
# [22] 括号生成
#

# @lc code=start
class Solution(object):
    def generateParenthesis(self, n):
        """
        :type n: int
        :rtype: List[str]
        """
        # 回溯法，画图仔细思考
        def dfs(cur_str, left, right):
            # 递归终止条件
            if left == 0 and right == 0:
                output.append(cur_str)
            if right < left:
                return
            # 递归表达
            if left > 0:
                dfs(cur_str + '(', left-1, right)
            if right > 0:
                dfs(cur_str + ')', left, right -1)
        
        output = []
        dfs("", n, n)
        return output
            
# @lc code=end

