/*
 * @lc app=leetcode.cn id=30 lang=cpp
 *
 * [30] 串联所有单词的子串
 */

// @lc code=start
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string, int> counts;
        for (string word : words)
            counts[word]++;
        int n = s.length(), num = words.size();
        vector<int> indexes;
        if(n==0 || num==0) {
            return indexes;
        }
        int len = words[0].length();
        // i: 子串的开始位置，单词的个数
        for (int i = 0; i < n - num * len + 1; i++) {
            unordered_map<string, int> seen;
            int j = 0;
            for (; j < num; j++) {
                string word = s.substr(i + j * len, len);
                if (counts.find(word) != counts.end()) {
                    seen[word]++;
                    if (seen[word] > counts[word])
                        break;
                } 
                else break;
            }
            // j等于单词个数，则表明成功找到子串
            if (j == num) indexes.push_back(i);
        }
        return indexes;
    }
};
// @lc code=end

