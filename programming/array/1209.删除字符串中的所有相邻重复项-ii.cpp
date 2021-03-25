/*
 * @lc app=leetcode.cn id=1209 lang=cpp
 *
 * [1209] 删除字符串中的所有相邻重复项 II
 */

// @lc code=start
class Solution {
public:
    string removeDuplicates(string s, int k) {
        // 很巧妙的使用栈，栈中存储的是个数，而不是字符
        stack<int> st;
        for(int i=0; i<s.size(); i++) {
            if(i ==0 || s[i] != s[i-1]) {
                st.push(1);
            } else {
                // 出现重复此时，当重复此时等于k时
                if(++st.top() == k) {
                    st.pop();
                    s.erase(i - k + 1, k);   // 原字符串删除k个重复的
                    i = i - k;     // 此时i要变
                }
            }
        }
        return s;
    }
};
// @lc code=end

