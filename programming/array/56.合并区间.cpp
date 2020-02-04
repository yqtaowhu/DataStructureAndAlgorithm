/*
 * @lc app=leetcode.cn id=56 lang=cpp
 *
 * [56] 合并区间
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int> > res;
        if(intervals.empty()) return res;
        sort(intervals.begin(), intervals.end());
        res.push_back(intervals[0]);
        //cout<<res[0]<<endl;
        for(int i=1; i<intervals.size();i++) {
            // 当前first大于维护的区间end,则当前区间为新的维护区间
            if(intervals[i][0] > res.back()[1]) {
                res.push_back(intervals[i]);
            } else {
                // 有重叠，则更新end
                res.back()[1] = max(res.back()[1], intervals[i][1]);
            }
        }
        return res;
    }
};
// @lc code=end

