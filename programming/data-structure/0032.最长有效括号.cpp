/*
 * @lc app=leetcode.cn id=32 lang=cpp
 *
 * [32] 最长有效括号
 */

// @lc code=start
class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size();
        if(n <= 1) return 0;
        stack<int> st;
        st.push(-1);
        int res = 0;
        for(int i=0; i < n; i++) {
            if(s[i] == '(') {
                st.push(i);
            } else {
                st.pop();
                if(st.empty()) {
                    st.push(i);
                } else {
                    res = max(res, i - st.top());
                }
            }
        }
        return res;
        
    }
};
// @lc code=end

