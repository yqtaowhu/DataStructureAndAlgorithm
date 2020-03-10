/*
 * @lc app=leetcode.cn id=189 lang=cpp
 *
 * [189] 旋转数组
 */

// @lc code=start
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int len=nums.size();
        if (len==0||k<=0) return;
        k=k%len;
        reverse(nums.begin(),nums.begin()+len-k);
        reverse(nums.begin()+len-k,nums.end());
        reverse(nums.begin(),nums.end());
    }
    /*
        void rotate(vector<int>& nums, int k) {
        int len=nums.size();
        if (len==0||k<=0) return;
        k=k%len;
        vector<int> v(nums.begin()+len-k,nums.end());
        for (int i=len-1;i>=k;i--) {
            nums[i]=nums[i-k];
        }
        for (int i=0;i<k;i++)
            nums[i]=v[i];
    }
    */
};
// @lc code=end

