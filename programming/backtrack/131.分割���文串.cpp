/*
 * @lc app=leetcode.cn id=131 lang=cpp
 *
 * [131] 分割回文串
 */

// @lc code=start
class Solution {
public:
    bool check(string &s) {
        int i=0, j = s.size()-1;
        while(i<j) {
            if(s[i++] != s[j--])
                return false;
        }
        return true;
    }

    void backtrace(vector<vector<string>> &res, vector<string> &cur, string s) {
        if(s.empty()) {
            res.push_back(cur);
            return;
        }
        for(int i=1; i<=s.size(); i++) {
            string prefix = s.substr(0,i);
            if(!check(prefix)) {
                continue;
            }
            cout<<prefix<<endl;
            cout<<s.substr(i)<<endl;
            cur.push_back(prefix);
            backtrace(res, cur, s.substr(i));
            cur.pop_back();
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> cur;
        backtrace(res, cur, s);
        return res;
    }
};
// @lc code=end

