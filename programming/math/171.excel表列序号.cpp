/*
 * @lc app=leetcode.cn id=171 lang=cpp
 *
 * [171] Excel表列序号
 */

// @lc code=start
class Solution {
public:
    int titleToNumber(string s) {
        int res=0,i=0;
        while (s[i]==' ') i++;
        for (;i<s.size()&&s[i]!=' ';i++) {
            int digit=s[i]-'A'+1;
            res=res*26+digit;
        }
        return res;
    }
};
// @lc code=end

