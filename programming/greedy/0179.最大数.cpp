/*
 * @lc app=leetcode.cn id=179 lang=cpp
 *
 * [179] 最大数
 */

// @lc code=start
class Solution {
public:
    // 贪心 + 自定义排序：比较两个数拼接后的两种顺序，
    // 若 a+b > b+a（字符串比较），则 a 应排在 b 前面。
    string largestNumber(vector<int>& nums) {
        vector<string> strs;
        for (int x : nums) strs.push_back(to_string(x));
        sort(strs.begin(), strs.end(),
             [](const string& a, const string& b) {
                 return a + b > b + a;
             });
        if (strs[0] == "0") return "0"; // 全是 0 的情况
        string res;
        for (auto& s : strs) res += s;
        return res;
    }
};
// @lc code=end
