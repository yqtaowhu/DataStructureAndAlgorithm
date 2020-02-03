#
# @lc app=leetcode.cn id=46 lang=python
#
# [46] 全排列
#

# @lc code=start
class Solution(object):
    def permute(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        def dfs(nums, size, path, used, res):
            if len(path) == size:
                res.append(path[:]) # path是引用，要进行值拷贝
                return
            # 查找临近点
            for i in range(size):
                # 判断条件
                if not used[i]:
                    used[i] = True
                    path.append(nums[i])

                    dfs(nums, size, path, used, res)

                    used[i] = False
                    path.pop()

        size = len(nums)
        if len(nums) == 0:
            return []

        used = [False for _ in range(size)]
        res = []
        dfs(nums, size, [], used, res)
        return res
        
# @lc code=end

