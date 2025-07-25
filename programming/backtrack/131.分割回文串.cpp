class Solution {
    bool isPalindrome(const string& s, int left, int right) {
        while (left < right) {
            if (s[left++] != s[right--]) {
                return false;
            }
        }
        return true;
    }

public:
    // 从答案的角度思考 
    vector<vector<string>> partition(string s) {
        int n = s.size();
        vector<vector<string>> ans;
        vector<string> path;

        // 考虑 s[i] ~ s[n-1] 怎么分割
        auto dfs = [&](this auto&& dfs, int i) {
            if (i == n) { // s 分割完毕
                ans.emplace_back(path);
                return;
            }
            for (int j = i; j < n; j++) { // 枚举子串的结束位置
                if (isPalindrome(s, i, j)) {
                    path.push_back(s.substr(i, j - i + 1)); // 分割！
                    // 考虑剩余的 s[j+1] ~ s[n-1] 怎么分割
                    dfs(j + 1);
                    path.pop_back(); // 恢复现场
                }
            }
        };

        dfs(0);
        return ans;
    }
};