/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */

// @lc code=start
class Solution {
public:
    // 寻找左侧边界的二分搜索
    int left_bound(vector<int> &nums, int target) {
        int len = nums.size();
        if(len < 1) return -1;
        int low = 0, high = len;
        while(low < high) {
            int mid = (low + high) >> 1;
            if(nums[mid] == target) {
                high = mid;
            } else if(nums[mid] < target) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        if(low == len) return -1;
        return nums[low] == target ? low: -1;
    }

    // 寻找右侧边界
    int right_bound(vector<int> &nums, int target) {
        int len = nums.size();
        if(len < 1) return -1;
        int low = 0, high = len;
        while(low < high) {
            int mid = (low + high) >> 1;
            if(nums[mid] == target) {
                low = mid + 1;
            } else if(nums[mid] < target) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        if(low == 0) return -1;
        return nums[low-1] == target ? (low-1) : -1;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int left_index = left_bound(nums, target);
        int right_index = right_bound(nums, target);
        vector<int> res={left_index, right_index};
        return res;
    }
};
// @lc code=end

