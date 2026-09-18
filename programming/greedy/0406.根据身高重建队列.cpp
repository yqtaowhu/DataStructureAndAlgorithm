/*
 * @lc app=leetcode.cn id=406 lang=cpp
 *
 * [406] 根据身高重建队列
 */

// @lc code=start
class Solution {
public:
    // 贪心：身高降序、k 升序排序后，按 k 依次插入。
    // 高的人先排好，矮的人插入不影响已排好的高个子的 k 值。
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 // 身高不同 -> 高的在前；身高相同 -> k 小的在前
                 return a[0] == b[0] ? a[1] < b[1] : a[0] > b[0];
             });
        vector<vector<int>> res;
        for (auto& p : people) {
            // 插到第 p[1] 个位置：此时 res 里都是 >= p[0] 的人，前面恰有 p[1] 个
            res.insert(res.begin() + p[1], p);
        }
        return res;
    }
};
// @lc code=end
