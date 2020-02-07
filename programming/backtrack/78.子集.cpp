/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 */

// @lc code=start
class Solution {
public:
    // 非常简单的回溯算法
    void subsets(vector<int>& nums, vector<int>& tmp, vector<vector<int>>& res, int beg) {
        res.push_back(tmp);
        for (int i = beg; i<nums.size(); i++) {
            tmp.push_back(nums[i]);
            subsets(nums, tmp, res, i + 1);
            tmp.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>res;
        vector<int>tmp;
        subsets(nums, tmp, res, 0);
        return res;
    }
    /*
    迭代的方法:
    class Solution(object):
    def subsets(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        res = [[]]
        for i in nums:
            res = res + [[i] + num for num in res]
        return re
    /*
};
// @lc code=end

