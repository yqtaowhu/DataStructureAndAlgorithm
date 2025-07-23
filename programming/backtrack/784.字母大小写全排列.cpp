class Solution {
public:
    vector<string> res;

    void dfs(string s, string &tmp, int beg) {
        res.push_back(tmp);
        for(int i=beg; i < s.size(); i++) {
            if (isalpha(s[i]) ) {
                tmp[i] ^= 32; //当前操作     
                dfs(s,tmp, i+1);
                tmp[i] ^= 32; //恢复现场 --> 反当前操作
            }
        }

    }

    vector<string> letterCasePermutation(string s) {
        if(s.empty()) return res;
        string tmp=s;
        dfs(s, tmp, 0);
        return res;
        
    }
};


class Solution {
public:
    vector<string> letterCasePermutation(string s) 
    {
        int n = s.size();
        vector<string> ans;
        string cur = s;

        function<void(int)> dfs = [&](int i) {
            if ( i==n )
            {
                ans.push_back(cur);
                return;
            }
            
            dfs(i+1); //不选此字符

            if ( isalpha(cur[i]) ) //选择此字符
            {
                cur[i] ^= ' '; //当前操作
                dfs(i+1);
                cur[i] ^= ' '; //恢复现场 --> 反当前操作
            }
        };
        dfs(0);

        return ans;
    }
}