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

    // 迭代方法
class Solution {
public:
    // []
    // 访问1  [], [1]
    // 访问2  [], [1], [2], [1, 2]
    // 访问3  [], [1,3], [2, 3], [1, 2, 3] 
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        res.push_back(vector<int> ());
        for(auto &num : nums) {
            int size = res.size();
            for(int i=0; i < size; i++) {
                vector<int> tmp(res[i].begin(), res[i].end());
                tmp.push_back(num);
                res.push_back(tmp);
            }
        }
        return res;
    }
};
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


// 选择的角度

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        vector<int> path;

        auto dfs = [&](this auto&& dfs, int i) -> void {
            if (i == n) { // 子集构造完毕
                ans.emplace_back(path);
                return;
            }

            // 不选 nums[i]
            dfs(i + 1);

            // 选 nums[i]
            path.push_back(nums[i]);
            dfs(i + 1);
            path.pop_back(); // 恢复现场
        };

        dfs(0);
        return ans;
    }
};