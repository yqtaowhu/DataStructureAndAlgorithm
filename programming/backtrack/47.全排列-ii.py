#
# @lc app=leetcode.cn id=47 lang=python
#
# [47] 全排列 II
#

# @lc code=start
class Solution(object):
    def permuteUnique(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        def dfs():
            if len(path) == size:
                res.append(path[:])
                return
            for i in range(size):
                if not used[i]:
                    # 避免重复的起点nums[i] == nums[i - 1]
                    # 同时要保证上次的元素没有被使用，如果正在使用前一个重复数字，则可以使用当前数字
                    if i > 0 and nums[i] == nums[i - 1] and not used[i - 1]:
                        continue

                    used[i] = True
                    path.append(nums[i])
                    dfs()
                    used[i] = False
                    path.pop()

        size = len(nums)
        if size == 0:
            return []

        nums.sort()

        used = [False] * len(nums)
        res,path = [], []
        dfs()
        return res
        
# @lc code=end

