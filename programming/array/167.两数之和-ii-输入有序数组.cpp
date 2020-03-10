/*
 * @lc app=leetcode.cn id=167 lang=cpp
 *
 * [167] 两数之和 II - 输入有序数组
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> res(2,0);
        int left = 0, right = numbers.size()-1;
        while(left < right) {
            if(numbers[left] + numbers[right] == target) {
                res[0] = left+1;
                res[1] = right+1;
                return res;
            } else if(numbers[left] + numbers[right] < target) {
                left++;
            } else {
                right--;
            }
        }
        return res;
    }
};
// @lc code=end

