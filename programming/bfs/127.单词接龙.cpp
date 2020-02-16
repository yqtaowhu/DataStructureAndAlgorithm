/*
 * @lc app=leetcode.cn id=127 lang=cpp
 *
 * [127] 单词接龙
 */

// @lc code=start
class Solution {
public:
int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    // 预处理词典, key:模式串 val: 满足模式串的单词数组
    unordered_map<string, vector<string> > map;
    bool flag = false;
    for(int i=0; i<wordList.size(); i++) {
        // 首先应该看是否能转换
        if(wordList[i] == endWord) {
            flag = true;
        }
        // 构建模式串
        //cout<<"word: "<<wordList[i]<<endl;
        for(int j=0; j<wordList[i].size(); j++) {
            string tmp = wordList[i];
            tmp[j] = '*';
            //cout<<tmp<<endl;
            map[tmp].push_back(wordList[i]);
        }
    }

    if(flag == false) {
        return 0;
    }

    //print_map(map);

    // string, depth
    queue<pair<string,int> > que;
    que.push({beginWord,1});
    unordered_map<string, int> visit;
    visit[beginWord] = 1;

    while(!que.empty()) {
        string s = que.front().first;
        int level = que.front().second;
        cout<<"s:" << s << " l: "<<level<<endl;
        que.pop();
        if(s == endWord) {
            return level;
        }
        
        // 取相邻的节点
        for(int i=0; i<s.size(); i++) {
            string tmp = s;
            tmp[i] = '*';
            // map[tmp] --> vector<string>
            for(auto w: map[tmp]) {
                // 未遍历
                if(visit.count(w) ==0) {
                    que.push({w, level+1});
                    visit[w] = 1;
                } 
            }
        }
    }
    return 0;
    }
};
// @lc code=end

/*

#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
#include<string>

using namespace std;


void print_map(unordered_map<string, vector<string> > map) {
    for(auto w:map) {
        string templat = w.first;
    }
}
int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    // 预处理词典, key:模式串 val: 满足模式串的单词数组
    unordered_map<string, vector<string> > map;
    bool flag = false;
    for(int i=0; i<wordList.size(); i++) {
        // 首先应该看是否能转换
        if(wordList[i] == endWord) {
            flag = true;
        }
        // 构建模式串
        //cout<<"word: "<<wordList[i]<<endl;
        for(int j=0; j<wordList[i].size(); j++) {
            string tmp = wordList[i];
            tmp[j] = '*';
            //cout<<tmp<<endl;
            map[tmp].push_back(wordList[i]);
        }
    }

    if(flag == false) {
        return 0;
    }

    //print_map(map);

    // string, depth
    queue<pair<string,int> > que;
    que.push({beginWord,1});
    unordered_map<string, int> visit;
    visit[beginWord] = 1;

    while(!que.empty()) {
        string s = que.front().first;
        int level = que.front().second;
        cout<<"s:" << s << " l: "<<level<<endl;
        que.pop();
        if(s == endWord) {
            return level;
        }
        
        // 取相邻的节点
        for(int i=0; i<s.size(); i++) {
            string tmp = s;
            tmp[i] = '*';
            // map[tmp] --> vector<string>
            for(auto w: map[tmp]) {
                // 未遍历
                if(visit.count(w) ==0) {
                    que.push({w, level+1});
                    visit[w] = 1;
                } 
            }
        }
    }
    return 0;
}


int main() {
    string beginWord = "hit", endWord = "cog";
    vector<string> wordList = {"hot","dot","dog","lot","log","cog"};
    for(auto w:wordList) {
        cout<<w<<" ";
    }
    cout<<endl;
    cout<<ladderLength(beginWord, endWord, wordList)<<endl;

}
*/