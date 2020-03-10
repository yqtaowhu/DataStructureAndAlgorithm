/*
 * @lc app=leetcode.cn id=187 lang=cpp
 *
 * [187] 重复的DNA序列
 */

// @lc code=start
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int m = s.size();
        vector<string> res;
        if(m<=10) {
            return res;
        }
        unordered_map<string, int> hash;
        for(int i=0; i<=m-10; i++) {
            string sub = s.substr(i, 10);
            
            //cout<<sub<<endl;
            if(hash.count(sub) && hash[sub] == 1) {
                res.push_back(sub);
            } 
            hash[sub] += 1;
        }
        return res; 
    }
};
// @lc code=end

