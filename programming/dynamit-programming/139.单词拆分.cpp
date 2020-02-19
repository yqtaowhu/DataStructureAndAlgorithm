/*
 * @lc app=leetcode.cn id=139 lang=cpp
 *
 * [139] 单词拆分
 */

// @lc code=start
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string> dict(wordDict.begin(), wordDict.end());
        set<int> memo;
        return dfs(s, dict, 0, memo);
    }
    bool dfs(string s, set<string>& wordDict, int index, set<int> &memo) {
        if(memo.count(index))
            return false;
        if(index >= s.size())
            return true;
        for(int i = index; i < s.size(); i++)
            if(wordDict.count(s.substr(index, i - index + 1)))
                if(dfs(s, wordDict, i + 1, memo))
                    return true;
        memo.insert(index);
        return false;
    }
};

// 可以用bfs的方法
class Solution {
public:
    // 记忆化回溯
    bool wordBreak(string s, vector<string>& wordDict) {
        queue<int> que;
        set<string> dict(wordDict.begin(), wordDict.end());
        vector<int> vis(s.size(), 0); //以start为开始的树
        que.push(0);
        
        while(!que.empty()) {
            int start = que.front();
            que.pop();

            // 遍历可能的相邻节点
            if(vis[start] == 0) {
                for(int end=start+1; end<=s.size(); end++) {
                    string prefix = s.substr(start, end-start); //从start点开始取可能的字符串
                    if(dict.count(prefix)) {
                        // 找到可能的单词
                        que.push(end);
                        if(end==s.size()) {
                            return true;
                        }
                    }
                }
                vis[start] = true;
            } 
        }
        return false;
    }
};


class Solution {
public:
    // dp[i]:表示前i个字符能否满足break条件
    // dp[i] =   s[j,i] && dp[j], 即如果s[j..i]在字典中，并且dp[j]为T,则其为true
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end()); //构建为set，方便查找

        vector<bool> dp(s.size()+1, false); //dp表示字符之间的隔板，n个字符有n+1个隔板
        dp[0] = true; //dp[0]是s[0]前面的隔板

        for(int i=1; i<=s.size(); ++i){
            for(int j=i; j>=0; --j){
                if(dict.find(s.substr(j,i-j))!=dict.end() && dp[j]){
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[s.size()];
    }
};

// @lc code=end

