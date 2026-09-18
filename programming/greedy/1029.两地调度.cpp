/*
 * @lc app=leetcode.cn id=1029 lang=cpp
 *
 * [1029] 两地调度
 */

// @lc code=start
class Solution {
public:
    // 贪心：按「去 A 相对去 B 的省钱程度」(costA - costB) 升序排序。
    // 差值越小（越负）说明去 A 越划算，排前一半去 A，后一半去 B，恰好各 N 人。
    int twoCitySchedCost(vector<vector<int>>& costs) {
        sort(costs.begin(), costs.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[0] - a[1] < b[0] - b[1];
             });
        int n = costs.size(), total = 0;
        for (int i = 0; i < n; i++) {
            // 前一半去 A 市，后一半去 B 市
            total += (i < n / 2) ? costs[i][0] : costs[i][1];
        }
        return total;
    }
};
// @lc code=end
