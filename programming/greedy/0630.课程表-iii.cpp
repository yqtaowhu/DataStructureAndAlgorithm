/*
 * @lc app=leetcode.cn id=630 lang=cpp
 *
 * [630] 课程表 III
 */

// @lc code=start
class Solution {
public:
    // 堆贪心：按截止时间升序排序，依次尝试加入课程。
    // 若加入后总耗时超过当前课程的截止时间，则从已选课程中「退掉耗时最长的一门」，
    // 这样能腾出最多时间给后面的课程，保证已选数量最优。
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(), courses.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[1] < b[1]; // 按截止时间
             });
        priority_queue<int> pq; // 大顶堆：已选课程的耗时
        int total = 0;
        for (auto& c : courses) {
            int dur = c[0], last = c[1];
            if (total + dur <= last) { // 能放下就选
                total += dur;
                pq.push(dur);
            } else if (!pq.empty() && pq.top() > dur) {
                // 放不下：若当前课比已选最耗时的课短，则替换（净省时）
                total += dur - pq.top();
                pq.pop();
                pq.push(dur);
            }
        }
        return pq.size();
    }
};
// @lc code=end
