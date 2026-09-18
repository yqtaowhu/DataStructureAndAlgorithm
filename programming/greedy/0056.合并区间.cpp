/*
 * @lc app=leetcode.cn id=56 lang=cpp
 *
 * [56] 合并区间
 */

// @lc code=start
class Solution {
public:
    // 区间贪心：按左端点升序排序，能合并就把右端点扩到最大
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[0] < b[0];
             });
        vector<vector<int>> res;
        for (auto& cur : intervals) {
            // res 为空，或当前区间左端点 > 上一个区间右端点（不相交）-> 新开一段
            if (res.empty() || cur[0] > res.back()[1]) {
                res.push_back(cur);
            } else {
                // 相交：合并，右端点取较大者
                res.back()[1] = max(res.back()[1], cur[1]);
            }
        }
        return res;
    }
};
// @lc code=end
