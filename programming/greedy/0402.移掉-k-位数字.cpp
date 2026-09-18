/*
 * @lc app=leetcode.cn id=402 lang=cpp
 *
 * [402] 移掉 K 位数字
 */

// @lc code=start
class Solution {
public:
    // 单调栈贪心：要让结果字典序最小，就尽量让高位小。
    // 遇到「栈顶 > 当前位」且还有删除配额时，删掉栈顶（削掉一个峰值）。
    string removeKdigits(string num, int k) {
        string stk;
        for (char c : num) {
            while (k > 0 && !stk.empty() && stk.back() > c) {
                stk.pop_back();
                k--;
            }
            stk.push_back(c);
        }
        // 若始终单调不减（如 12345），配额没删完，从末尾删剩余的 k 位
        while (k > 0) { stk.pop_back(); k--; }
        // 去除前导零
        int pos = 0;
        while (pos < (int)stk.size() && stk[pos] == '0') pos++;
        string res = stk.substr(pos);
        return res.empty() ? "0" : res;
    }
};
// @lc code=end
