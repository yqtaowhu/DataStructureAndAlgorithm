/*
 * @lc app=leetcode.cn id=31 lang=cpp
 *
 * [31] 下一个排列
 */

// @lc code=start
class Solution {
public:
    // 1 5 8 4 7 6 5 3 1
    // a[i+1] > a[i]的位置，  4 
    // 交换4，5 ，然后逆序
    void nextPermutation(vector<int>& nums) {
        int len = nums.size();
        if(len <= 1) return;
        int i = len -2;
        while(i>=0 && nums[i+1] <= nums[i]) i--;
        if(i>=0) {
            // 从后往前找到第一个比4大的数，进行交换
            int j = len-1;
            while(j>i && nums[j] <= nums[i]) j--;
            swap(nums[i], nums[j]);
        }
        reverse(nums.begin()+i+1,nums.end());
        
    }
};
// @lc code=end

