class Solution {
public:
    // 这里需要思考左到右是不行的 dp[i]: 到i时最大的分数
    // 从右到左，dp[i]: i往后得到的最大分数
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<long long> dp(n + 1, 0); // 解决每道题及以后题目的最大分数
        for (int i = n - 1; i >= 0; --i) {
            int p = questions[i][0];
            int b = questions[i][1];
            dp[i] = max(dp[i + 1], p + dp[min(n, i + b + 1)]);
        }
        return dp[0];
    }
};