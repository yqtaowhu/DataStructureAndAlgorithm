/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */

// @lc code=start
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(int i=0; i<s.size(); i++) {
            if(s[i] == '(' || s[i] == '[' || s[i] == '{') {
                st.push(s[i]);
            } else {
                if(st.empty()) return false;
                char c = st.top();
                st.pop();
                if((s[i] == ')' && c != '(') || (s[i] == ']' && c != '[') || 
                    (s[i] == '}' && c != '{'))
                    return false;          
            }
        } 
        
        return st.empty();
    }
};
// @lc code=end

