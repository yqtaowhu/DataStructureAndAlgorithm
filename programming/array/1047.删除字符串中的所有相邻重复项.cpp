/*
 * @lc app=leetcode.cn id=1047 lang=cpp
 *
 * [1047] 删除字符串中的所有相邻重复项
 */

// @lc code=start
class Solution {
public:
    string removeDuplicates(string S) {
        // 很明显的栈操作, 用字符串模拟栈
        string st;
        for(int i=0; i<S.size(); i++) {
            if(st.empty() || st.back() != S[i]) {
                st.push_back(S[i]);
            } else {
                st.pop_back();
            }
        }
        return st;
    }
};
// @lc code=end

