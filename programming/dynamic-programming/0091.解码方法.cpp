/*
 * @lc app=leetcode.cn id=91 lang=cpp
 *
 * [91] 解码方法
 */

// @lc code=start
class Solution {
public:
    // 1. s[i] = 0 , 如果s[i-1] = 1,2  dp[i]=dp[i-2], 否则为0
    // 2. s[i-1]=1|| s[i-1]=2 && 1<=s[i]<=6 dp[i] = dp[i-1] + dp[i-2]
    // 参考资料:https://leetcode-cn.com/problems/decode-ways/solution/c-wo-ren-wei-hen-jian-dan-zhi-guan-de-jie-fa-by-pr/
    int numDecodings(string s) {
        if (s[0] == '0') return 0;
        int pre = 1, curr = 1;//dp[-1] = dp[0] = 1
        for (int i = 1; i < s.size(); i++) {
            int tmp = curr;
            if (s[i] == '0') {
                if (s[i - 1] == '1' || s[i - 1] == '2') {
                    curr = pre;
                }
                else return 0;
            }
            else if (s[i - 1] == '1' || (s[i - 1] == '2' && s[i] >= '1' && s[i] <= '6'))
                curr = curr + pre;
            pre = tmp;
        }
        return curr;
    }
};
// @lc code=end

