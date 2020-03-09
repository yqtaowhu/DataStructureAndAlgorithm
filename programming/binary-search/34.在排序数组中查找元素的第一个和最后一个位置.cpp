/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */

// @lc code=start
class Solution {
public:
    int left_bound(vector<int> &data, int target) {
        // 查找左边界的模板
        int left = 0, right = data.size() - 1;
        while(left < right) {
            int mid = (left + right) >> 1;
            if(data[mid] >= target) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        if(data[left] != target) return -1;
        else return left;
    }

    int right_bound(vector<int>& data, int target) {
        // 查找左边界的模板
        int left = 0, right = data.size() - 1;
        while(left < right) {
            int mid = (left + right + 1) >> 1;
            if(data[mid] <= target) {
                left = mid;
            } else {
                right = mid - 1;
            }
        }
        if(data[left] != target) return -1;
        else return left;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res(2, -1);
        if(nums.empty()) return res;
        res[0] = left_bound(nums, target);
        res[1] = right_bound(nums, target);
        return res;
    }
};
// @lc code=end

