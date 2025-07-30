class Solution {
public:
    int maxUniqueSplit(string s) {
        dfs(s, 0);
        return ans;
    }

    void dfs(string& s, int pos) {
        // 剪枝
        if (s.size() - pos + us.size() <= ans) return;
        if (pos == s.size()) {
            ans = max(ans, (int)us.size());
            return;
        }

        string temp;
        for (int i = pos; i < s.size(); i++) {
            temp += s[i];
            if (us.find(temp) == us.end()) {
                us.insert(temp);
                dfs(s, i + 1);
                us.erase(temp);
            }
        }
    }
private:
    int ans = 0;
    unordered_set<string> us;
};