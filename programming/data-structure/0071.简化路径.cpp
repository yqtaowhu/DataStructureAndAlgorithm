/*
 * @lc app=leetcode.cn id=71 lang=cpp
 *
 * [71] 简化路径
 */

// @lc code=start
class Solution {
public:
    string simplifyPath(string path) {
       	string res, tmp;
        vector<string> stk;
        stringstream ss(path);
        while (getline(ss, tmp, '/')) {
            // 首先空和.不进行操作
            if (tmp == "" || tmp == ".") continue;
            // 弹出栈的条件
            if (tmp == ".." && !stk.empty()) 
                stk.pop_back();
            // 进栈
            else if (tmp != "..")
                stk.push_back(tmp);
        }
        for (auto str : stk) res += "/" + str;
        return res.empty() ? "/" : res; 
    }
};
// @lc code=end

