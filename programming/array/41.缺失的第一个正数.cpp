/*
 * @lc app=leetcode.cn id=41 lang=cpp
 *
 * [41] 缺失的第一个正数
 */

// @lc code=start
class Solution {
public:
    // o(n)复杂度，一定记得桶排序
    int firstMissingPositive(vector<int>& nums) {
        int len = nums.size();
        if(len < 1) return 1;
        for(int i=0; i< len; i++) {
            // 涉及到索引取值，要注意范围！nums[i] > 0 && nums[i] <= len
            // nums[i]-1 != i && nums[i] != nums[nums[i] - 1] 注意避免死循环
            while(nums[i] > 0 && nums[i] <= len && nums[i]-1 != i && nums[i] != nums[nums[i] - 1]) {
                swap(nums[i], nums[nums[i]-1]);
            }
        }
        for(int i=0; i< len; i++) {
            if(nums[i]-1 != i)
                return i+1;
        }
        return len + 1;
    }
};
// @lc code=end

