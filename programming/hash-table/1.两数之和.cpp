/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start

#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    // 思路，哈希表  key: 需要找到元素   value: 所在位置
    vector<int> twoSum(vector<int>& nums, int target) {
       unordered_map <int, int> map;
       vector<int> res;
       for (int i=0; i< nums.size(); i++) {
           if(map.find(nums[i]) != map.end()) {
               res.push_back(map[nums[i]]);
               res.push_back(i);
               break;
           } else {
               map[target - nums[i]] = i;
           }
       }
    return res;
    }
};
// @lc code=end