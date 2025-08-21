class Solution {
public:
    // dp[i] 以i结尾的最长递增子序列, 非严格递增
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        int n = obstacles.size();
        vector<int> dp(n, 1), g;
        for(int i=0; i<n; i++) {
            auto it = upper_bound(g.begin(), g.end(), obstacles[i]);
            if(it == g.end()) {
                g.push_back(obstacles[i]);
                dp[i] = g.size();
            } else {
                *it = obstacles[i];
                dp[i] = it - g.begin() + 1;
            }
        }
        return dp;
    }
};