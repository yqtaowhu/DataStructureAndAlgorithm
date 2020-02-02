/*
 * @lc app=leetcode.cn id=32 lang=cpp
 *
 * [32] 最长有效括号
 */

// @lc code=start
class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size(),maxLen=0;
        if (n<2) return 0;
        stack<int> st;
        for (int i=0;i<n;i++) {
            if (s[i]=='(') st.push(i);
            else {
                if (st.empty()) st.push(i);
                else {
                    if (s[st.top()]=='(') {
                        st.pop();
                        maxLen=max(maxLen,i-(st.empty()? -1:st.top()));
                    }
                    else st.push(i);
                }
            }
        }
        return maxLen;
    }
};
// @lc code=end

