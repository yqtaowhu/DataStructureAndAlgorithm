/*
 * @lc app=leetcode.cn id=88 lang=cpp
 *
 * [88] 合并两个有序数组
 */

// @lc code=start
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=m-1, j=n-1;
        while(i>=0 && j>=0) {
            if(nums1[i] < nums2[j]) {
                nums1[i+j+1] = nums2[j]; 
                j--;
            } else{
                nums1[i+j+1] = nums1[i];
                i--;
            }
        }
        // 注意nums2有剩余元素
        while(j>=0) {
            nums1[j] = nums2[j];
            j--;
        }
    }
};
// @lc code=end

