/*
 * @lc app=leetcode.cn id=300 lang=cpp
 *
 * [300] 最长上升子序列
 */

// @lc code=start
class Solution {
public:
    // 贪心 + 二分查找， 特别注意这个二分查找的写法啊，即找到其插入的位置
    int lengthOfLIS(vector<int>& nums) {
        int size = nums.size();
        if(size <= 0) {
            return 0;
        }
        int res = 0;
        vector<int> v;
        v.push_back(nums[0]);
        for(int i=1; i < size; i++) {
            if(nums[i] > v.back()) {
                v.push_back(nums[i]);
            } else {
                int left = 0, right = v.size()-1;
                while(left <= right) {
                    int mid = (left + right) / 2;
                    if(v[mid] >= nums[i]) {
                        right = mid - 1;
                    }  else {
                        left = mid + 1;
                    }
                }
                v[left] = nums[i];
            }
        }
        return v.size();
    }
};
// @lc code=end

