/*
 * @lc app=leetcode.cn id=90 lang=cpp
 *
 * [90] 子集 II
 */

// @lc code=start
class Solution {
public:
    /*
    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        n=len(nums)
        nums.sort()
        res=[[]]
        pre=[]
        for i in range(n):
            if(i>0 and nums[i]==nums[i-1]):
                pre=[tmp+[nums[i]] for tmp in pre]
            else:
                pre=[tmp+[nums[i]] for tmp in res]
            res+=pre
        return res
    */
    void dfs(vector<vector<int> > &subsets, vector<int> &subset, vector<int> &nums, int beg) {
        subsets.push_back(subset);

        for(int i=beg; i<nums.size(); i++) {
            if(i!=beg && nums[i] == nums[i-1]) 
                continue;
            subset.push_back(nums[i]);
            dfs(subsets, subset, nums, i+1);
            subset.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int> > subsets;
        vector<int> subset;
        dfs(subsets, subset, nums, 0);
        return subsets;
    }
};
// @lc code=end

