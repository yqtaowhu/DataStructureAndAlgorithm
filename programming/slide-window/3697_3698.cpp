
/*
给你两个字符串 word1 和 word2 。

如果一个字符串 x 重新排列后，word2 是重排字符串的 
前缀
 ，那么我们称字符串 x 是 合法的 。

请你返回 word1 中 合法 
子字符串
 的数目。
*/

class Solution {
public:
    long long validSubstringCount(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        if (m < n) return 0;
        unordered_map<char, int> count, need;
        for(auto &c : word2) {
            need[c]++;
        }
        int cnt = need.size();
        int i = 0, j = 0;
        long long res = 0;
        while(j < m) {
            char s = word1[j];
            count[s]++;
            if(need.count(s)) {
                if(count[s] == need[s]) {
                    cnt--;
                }
            }
            while(i <= j && cnt == 0) {
                res += m - j;
                char t = word1[i];
                i++;
                if(need.count(t) && --count[t] < need[t]) {
                    cnt++;
                    break;
                }
            }
            j++;
        }
        return res;
    }
};