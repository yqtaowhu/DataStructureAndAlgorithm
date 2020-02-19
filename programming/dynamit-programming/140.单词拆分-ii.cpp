/*
 * @lc app=leetcode.cn id=140 lang=cpp
 *
 * [140] 单词拆分 II
 */

// @lc code=start
class Solution {
public:
    void dfs(int i, const vector<bool>& f, const string &s,
             const unordered_set<string>& wordSet,
             vector<string>& cur_string, vector<string>& ans) {
        if (i == 0) {
            string tmp = "";
            for (int k = cur_string.size() - 1; k >= 0; k--) {
                tmp += cur_string[k];
                if (k > 0)
                    tmp += " ";   
            }
            ans.push_back(tmp);
            return;
        }
        for (int j = 0; j < i; j++) {
            string cur = s.substr(j, i - j);
            if (f[j] && wordSet.find(cur) != wordSet.end()) {
                cur_string.push_back(cur);
                dfs(j, f, s, wordSet, cur_string, ans);
                cur_string.pop_back();
            }
        }
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        vector<bool> f(n + 1, false); // 为了方便，f数组的下标从1开始。
        f[0] = true;
        for (int i = 1; i <= n; i++)
            for (int j = 0; j < i; j++) {
                string cur = s.substr(j, i - j);
                if (wordSet.find(cur) != wordSet.end())
                    f[i] = f[i] | f[j];
            }
        vector<string> ans;
        vector<string> cur_string;
        dfs(n, f, s, wordSet, cur_string, ans);
        return ans;
    }
};

/*
超时:
class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string> res;
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        queue<pair<int, string> > que; //存储每个单词的开始位置
        que.push({0, ""});
        while(!que.empty()) {
            int start = que.front().first;
            string tmp = que.front().second;

            que.pop();
            for(int end=start+1; end<=s.size(); end++) {
                string prefix = s.substr(start, end-start);
                if(dict.count(prefix)) {
                    string tmp2 = tmp + " " + prefix;
                    //cout<<tmp2<<endl;
                    que.push({end, tmp2});
                    if(end == s.size()) {
                        tmp2.erase(0,tmp2.find_first_not_of(" "));
                        cout<<tmp2<<endl;
                        res.push_back(tmp2);
                    }
                }
            }   
        }
        return res;
    }
};
*/
// @lc code=end

