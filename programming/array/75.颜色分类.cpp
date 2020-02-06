/*
 * @lc app=leetcode.cn id=75 lang=cpp
 *
 * [75] 颜色分类
 */

// @lc code=start
class Solution {
public:
    void sortColors(vector<int>& nums) {
        // p0:0 的右边界， p2：2的左边界
        int p0 = 0, p2 = nums.size()-1, cur=0;
        while(cur<=p2) {
            //
            if(nums[cur] == 0) {
                swap(nums[cur++], nums[p0++]);
            } else if(nums[cur] == 2) {
                swap(nums[cur], nums[p2--]); // 此时cur不加1,p2--
            } else {
                cur++; // 当为1时，直接++
            }
        }
    }
};
// @lc code=end

