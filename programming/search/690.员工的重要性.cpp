/*
 * @lc app=leetcode.cn id=690 lang=cpp
 *
 * [690] 员工的重要性
 */

// @lc code=start
/*
// Employee 由判题系统提供：
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/
// 以员工 id 为节点、直接下属为边构成一棵树/森林，从目标 id 出发 DFS/BFS 累加即可。
class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        unordered_map<int, Employee*> mp;
        for (auto* e : employees) mp[e->id] = e;
        int ans = 0;
        queue<int> q; q.push(id);
        while (!q.empty()) {
            Employee* e = mp[q.front()]; q.pop();
            ans += e->importance;
            for (int sub : e->subordinates) q.push(sub);
        }
        return ans;
    }
};
// @lc code=end
