/*
 * @lc app=leetcode.cn id=33 lang=cpp
 *
 * [33] 搜索旋转排序数组
 */

// @lc code=start
class Solution {
public:
    // 特别注意这个二分的写法
    int search_lowers_index(vector<int> &nums) {
        int left = 0, right = nums.size() -1;
        while(left < right) {
            int mid = (left + right) / 2;
            if(nums[mid] > nums[right])
                left = mid + 1;
            else right = mid;
        }
        return left;
    }

    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() -1 ;
        int low_index = search_lowers_index(nums);
        while(left <= right) {
            int mid = (left + right) / 2;
            int real_mid = (mid + low_index) % nums.size();
            //cout << real_mid << endl;
            if(nums[real_mid] == target) {
                return real_mid;
            } else if(nums[real_mid] > target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return -1;
    }
};
// @lc code=end

