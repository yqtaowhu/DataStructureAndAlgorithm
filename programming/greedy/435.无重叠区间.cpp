/*
 * @lc app=leetcode.cn id=435 lang=cpp
 *
 * [435] 无重叠区间
 */

// @lc code=start
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        // 贪心算法，对尾结点进行排序，尽量选择尾结点小的，给后面流出空间
        int size = intervals.size();
        if(size <= 1) return 0;
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });
        int res = 0, tail = intervals[0][1];
        for(int i=1; i < size; i++) {
            // 当前起点小于上一个尾点,则删除这个区间
            if(intervals[i][0] < tail) {
                res++;
            } else {  // 起点大于前一个尾点，更新尾点
                tail = intervals[i][1];
            }
        }
        return res;
    }
};
// @lc code=end

