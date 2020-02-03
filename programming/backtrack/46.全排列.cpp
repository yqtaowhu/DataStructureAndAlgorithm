/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */

// @lc code=start
class Solution {
public:
    vector<vector<int> > permute(vector<int>& nums) {
        int length = nums.size();
        vector<vector<int> > res;
        if(length == 0)
            return res;
        
        permutationRecursively(nums, 0, length, res);
        
        return res;
    }
    
    void permutationRecursively(vector<int> &nums, int mStart, int length, vector<vector<int> > &res){
        if(mStart == length - 1){
            res.push_back(nums);
            return;
        }
        
        for(int i = mStart; i < length; i++){
            swap(nums[mStart], nums[i]);
            permutationRecursively(nums, mStart + 1, length, res);
            swap(nums[mStart], nums[i]);
        }
    }
};
// @lc code=end

