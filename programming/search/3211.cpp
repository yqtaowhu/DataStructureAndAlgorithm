class Solution {
public:
    vector<string> validStrings(int n) {
        vector<string> ans;
        string path(n, 0);

        auto dfs = [&](auto&& dfs, int i) -> void {
            if (i == n) {
                ans.push_back(path); // 注意这里复制了一份 path，需要 O(n) 时间
                return;
            }

            // 填 1
            path[i] = '1';
            dfs(dfs, i + 1);

            // 填 0
            if (i == 0 || path[i - 1] == '1') {
                path[i] = '0'; // 直接覆盖
                dfs(dfs, i + 1);
            }
        };

        dfs(dfs, 0);
        return ans;
    }
};