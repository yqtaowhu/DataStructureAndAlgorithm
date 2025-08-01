class Solution {
public:
    vector<int> tmp;
    vector<vector<int>> res;
    void dfs(int n, int k, int beg) {
        if(tmp.size() == k) {
            res.push_back(tmp);
            return;
        }
        // 这里可以进行剪枝
        for(int i=beg; i <= n - (k - tmp.size()) + 1; i++) {
            tmp.push_back(i);
            dfs(n, k, i+1);
            tmp.pop_back();
        }

    }
    vector<vector<int>> combine(int n, int k) {
        dfs(n, k, 1);
        return res;
        
    }
};