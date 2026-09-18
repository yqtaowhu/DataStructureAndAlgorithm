/*
 * @lc app=leetcode.cn id=399 lang=cpp
 *
 * [399] 除法求值
 */

// @lc code=start
// 把 a/b=k 看成带权有向边 a->b(权 k) 与 b->a(权 1/k)。
// 查询即求起点到终点路径上权值之积，用 BFS 边扩边累乘即可。
class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations,
                                vector<double>& values,
                                vector<vector<string>>& queries) {
        unordered_map<string, unordered_map<string, double>> g;
        for (int i = 0; i < (int)equations.size(); i++) {
            g[equations[i][0]][equations[i][1]] = values[i];
            g[equations[i][1]][equations[i][0]] = 1.0 / values[i];
        }
        vector<double> ans;
        for (auto& qr : queries) {
            string s = qr[0], t = qr[1];
            if (!g.count(s) || !g.count(t)) { ans.push_back(-1.0); continue; }
            if (s == t) { ans.push_back(1.0); continue; }
            unordered_map<string, double> dist;        // 起点到各点的乘积
            queue<string> q;
            q.push(s); dist[s] = 1.0;
            double res = -1.0;
            while (!q.empty() && res < 0) {
                string u = q.front(); q.pop();
                for (auto& [v, w] : g[u]) {
                    if (dist.count(v)) continue;
                    dist[v] = dist[u] * w;
                    if (v == t) { res = dist[v]; break; }
                    q.push(v);
                }
            }
            ans.push_back(res);
        }
        return ans;
    }
};
// @lc code=end
