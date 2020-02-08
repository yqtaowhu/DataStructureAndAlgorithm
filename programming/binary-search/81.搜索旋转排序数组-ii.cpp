/*
 * @lc app=leetcode.cn id=81 lang=cpp
 *
 * [81] 搜索旋转排序数组 II
 */

// @lc code=start
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int left = 0, right =  nums.size()-1, mid;
        while(left<=right) {
            mid = (left + right) >> 1;
            if(nums[mid] == target) return true;
            // the only difference from the first one, trickly case, just updat left and right
            if( (nums[left] == nums[mid]) && (nums[right] == nums[mid]) ) {
                ++left; --right;
            }
            else if(nums[left] <= nums[mid]) {
                if( (nums[left]<=target) && (nums[mid] > target) ) 
                    right = mid-1;
                else left = mid + 1; 
            }
            else {
                if((nums[mid] < target) &&  (nums[right] >= target) ) 
                    left = mid+1;
                else right = mid-1;
            }
        }
        return false;
    }    
};
// @lc code=end

