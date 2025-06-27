class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        if(intervals.empty()) return res;
        int m = intervals.size();
        sort(intervals.begin(), intervals.end(), [](vector<int> &a,  vector<int> &b) {
            return a[0] < b[0];
        });
        res.push_back(intervals[0]);
        for(int i=1; i < m; i++) {
            // 头大于尾
            if(intervals[i][0] > res.back()[1]) {
                res.push_back(intervals[i]);
            } else {
                // 可以合并，更新尾巴
                res.back()[1] = max(res.back()[1], intervals[i][1]);
            }
        }
        return res;
    }
};