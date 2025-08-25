class Solution {
public:
    // dp[i] 当前字符串的最少删除次数
    int minExtraChar(string s, vector<string>& dictionary) {
        int n = s.size();
        set<string> st(dictionary.begin(), dictionary.end());
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        for(int i=1; i<=n; i++) {
            dp[i] = dp[i - 1] + 1; // 不选
            // 枚举选哪个
            for(int j=i-1; j>=0; j--) {
                string cur = s.substr(j, i - j);
                if(st.find(cur) != st.end()) {
                    dp[i] = min(dp[i], dp[j]);
                }
            }
        }
        return dp[n];
    }
};