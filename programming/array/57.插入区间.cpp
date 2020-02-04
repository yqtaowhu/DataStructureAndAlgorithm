/*
 * @lc app=leetcode.cn id=57 lang=cpp
 *
 * [57] 插入区间
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        int left = newInterval[0],right = newInterval[1];
        for(int i = 0;i<intervals.size();i++) {
            // end下于插入的起点，保存结果
            if(intervals[i][1] < newInterval[0]) {
                res.push_back(intervals[i]);
            }
            // 有交叉，求出交叉的左右点
            else if( intervals[i][0] <= newInterval[1]) {
                left = min(left, intervals[i][0]);
                right = max(right,intervals[i][1]);
            }
        } 
        res.push_back({left,right});
        for(int i = 0;i<intervals.size();i++) {
            // 起点大于插入终点
            if(intervals[i][0] > newInterval[1]) {
                res.push_back(intervals[i]);
            }
        }
        return res;
    }
};
// @lc code=end

