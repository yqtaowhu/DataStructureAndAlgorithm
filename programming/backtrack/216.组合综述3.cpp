// 经典回溯模版题，记得剪枝操作


class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;
    int tmp = 0;

    void dfs(int k, int n, int beg) {
        if(tmp == n && path.size() == k) {
            res.push_back(path);
            return;
        }
        // 剪枝
        for(int i=beg; i <= 9 && tmp <= n-i && path.size() < k; i++) {
            tmp += i;
            path.push_back(i);
            dfs(k, n, i+1);
            tmp -= i;
            path.pop_back();
        }


    }
    vector<vector<int>> combinationSum3(int k, int n) {
        dfs(k, n, 1);
        return res;
        
    }
};