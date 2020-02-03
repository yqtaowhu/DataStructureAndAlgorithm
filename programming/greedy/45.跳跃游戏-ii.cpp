/*
 * @lc app=leetcode.cn id=45 lang=cpp
 *
 * [45] 跳跃游戏 II
 */

// @lc code=start
class Solution {
public:
    int jump(vector<int>& nums) {
        int i = 0, n = nums.size(), step = 0, end = 0, maxend = 0;
        while (end < n - 1) {
        	step++;
            // end为当前步数可以到达的最远的距离
            for (;i <= end; i++) {
            	maxend = max(maxend, i + nums[i]);
                if (maxend >= n - 1) return step;
            }
            if(end == maxend) break;
            // 更新end,下一个循环步数+1
            end = maxend;
        }
        return n == 1 ? 0 : -1;
    }
};
// @lc code=end

