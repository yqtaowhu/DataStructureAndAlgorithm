/*
 * @lc app=leetcode.cn id=169 lang=cpp
 *
 * [169] 多数元素
 */

// @lc code=start
class Solution {
public:
    // 位运算的方法，同137题
    int majorityElement(vector<int>& nums) {
        int m = nums.size(), res = 0;
        for(int bit=0; bit<32; bit++) {
            int count = 0;
            for(auto &n:nums) {
                // 统计1的个数
                count += (n >> bit) & 1;
            }
            // 如果当前1的个数超过了一半
            if(count > m/2) {
                res += 1<<bit;
            }
        }
        return res;
    }
    // 投票算法
    int majorityElement(vector<int>& nums) {
        int major, counts = 0, n = nums.size();
        for (int i = 0; i < n; i++) {
            if (!counts) {
                major = nums[i];
                counts = 1;
            }
            else counts += (nums[i] == major) ? 1 : -1;
        }
        return major;
    }
};
// @lc code=end

