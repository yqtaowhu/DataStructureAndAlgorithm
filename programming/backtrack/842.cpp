class Solution {
public:
    vector<int> ans;
    bool check(){
        if(ans.size() < 3) return true;
        return (long long)ans.back() == (long long)ans[ans.size() - 2] + (long long)ans[ans.size() - 3]; 
    }
    bool dfs(string& s, int ind){
        if(ind >= s.size()) return ans.size() > 2; // 出口，ans.size()大于2表示找到一个合法的答案了
        if(s[ind] == '0'){
            ans.push_back(0);
            if(check() && dfs(s, ind + 1)) return true; // 本次选择合法并且后续搜索也找到答案
            ans.pop_back();
            return false; // 回溯
        }
        long long cur = 0; // 枚举所有不超过INT_MAX的数作为本层选择
        while(ind < s.size()){
            cur = cur * 10 + s[ind++] - '0';
            if(cur > INT_MAX) return false; // 枚举已经超过INT_MAX却还没找打答案，搜索失败
            ans.push_back(cur);
            if(check() && dfs(s, ind)) return true; // 本次选择合法并且后续搜索也找到答案
            ans.pop_back();
        }
        return false; // 回溯
    }
    vector<int> splitIntoFibonacci(string s) {
        if(dfs(s, 0)) return ans;
        return {};
    }
};