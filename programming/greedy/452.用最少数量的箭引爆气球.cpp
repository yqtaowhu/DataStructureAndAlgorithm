/*
 * @lc app=leetcode.cn id=452 lang=cpp
 *
 * [452] 用最少数量的箭引爆气球
 */

// @lc code=start
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if(points.empty() || points[0].empty()) {
            return 0;
        }
        // 贪心算法，按区间末尾进行升序排列
        sort(points.begin(), points.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });
        int size = points.size();
        int res = 1, tail = points[0][1];
        for(int i=1; i<size; i++) {
            // 当前起点大于尾结点，则不能射中,增加一支箭，同时更新尾结点的值
            if(points[i][0] > tail) {
                res++;
                tail = points[i][1]; 
            }
        }
        return res;
    }
};
// @lc code=end

