/*
 * @lc app=leetcode.cn id=438 lang=cpp
 *
 * [438] 找到字符串中所有字母异位词
 */

// @lc code=start
#include<iostream>
#include<unordered_map>
#include<vector>

using namespace std;
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int left=0, right = 0;
        unordered_map<char,int> needs, windows;
        for(auto c:p) needs[c]++;

        vector<int> res;
        int match=0;
        while(right<s.size()) {
            char c1 = s[right];
            if(needs.count(c1)) {
                windows[c1]++;
                if(windows[c1] == needs[c1]) {
                    match++;
                }
            }
            right++;
            while(match == needs.size()) {
                // 满足所含字母条件且长度合适
                if(right-left == p.size()) {
                    res.push_back(left);
                }
                char c2 = s[left];
                if(needs.count(c2)) {
                    windows[c2]--;
                    if(windows[c2] < needs[c2]) {
                        match--;
                    }
                }
                left++;
            }
        }
        return res;
    }
};
// @lc code=end

