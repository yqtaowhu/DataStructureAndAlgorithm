/*
 * @lc app=leetcode.cn id=1125 lang=cpp
 *
 * [1125] 最小的必要团队
 *
 * 状态压缩 DP（最小覆盖型）。把每种必备技能映射到一个二进制位，
 * mask 表示"已经覆盖的技能集合"。每个人的技能也压成一个整数 pmask[i]。
 * dp[mask] = 覆盖 mask 中所有技能所需的最少人数；
 * pre / choose 记录转移来源，用于还原具体的人员编号。
 */

// @lc code=start
class Solution {
public:
    vector<int> smallestSufficientTeam(vector<string>& req_skills,
                                       vector<vector<string>>& people) {
        int n = req_skills.size(), m = people.size();
        unordered_map<string, int> sid;
        for (int i = 0; i < n; ++i) sid[req_skills[i]] = i;

        // 每个人的技能集合压成二进制
        vector<int> pmask(m, 0);
        for (int i = 0; i < m; ++i)
            for (const string& s : people[i])
                pmask[i] |= 1 << sid[s];

        const int INF = 0x3f3f3f3f;
        vector<int> dp(1 << n, INF), pre(1 << n, -1), choose(1 << n, -1);
        dp[0] = 0;
        for (int mask = 0; mask < (1 << n); ++mask) {
            if (dp[mask] == INF) continue;
            for (int i = 0; i < m; ++i) {
                int nxt = mask | pmask[i]; // 加入第 i 个人后覆盖的技能
                if (dp[mask] + 1 < dp[nxt]) {
                    dp[nxt] = dp[mask] + 1;
                    pre[nxt] = mask;   // 记录从哪个状态转移来
                    choose[nxt] = i;   // 记录这一步选了谁
                }
            }
        }

        // 从全集状态沿 pre 回溯，还原团队成员
        vector<int> ans;
        for (int mask = (1 << n) - 1; mask; mask = pre[mask]) {
            ans.push_back(choose[mask]);
        }
        return ans;
    }
};
// @lc code=end
