/*
 * @lc app=leetcode.cn id=1288 lang=cpp
 *
 * [1288] 删除被覆盖区间
 */

// @lc code=start
class Solution {
public:
    // 贪心：左端点升序、左端点相同时右端点降序排序。
    // 这样遍历时，只要当前右端点 <= 已保留的最大右端点，就说明被覆盖。
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[0] == b[0] ? a[1] > b[1] : a[0] < b[0];
             });
        int covered = 0, maxRight = 0;
        for (auto& in : intervals) {
            if (in[1] <= maxRight) covered++;   // 右端点被前面的区间包住
            else maxRight = in[1];              // 否则刷新最右边界
        }
        return (int)intervals.size() - covered; // 剩余即未被覆盖的区间数
    }
};
// @lc code=end
