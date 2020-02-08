/*
 * @lc app=leetcode.cn id=89 lang=cpp
 *
 * [89] 格雷编码
 */

// @lc code=start
class Solution {
public:
    // n = 1 res = [0, 1]
    // n = 2时
    // a. res的每一位二进制前加0, 十进制表示不变
    // b. res集合中逆序二进制放1  即 [1,0] -> [11, 10], 加上十进制的t*2
    vector<int> grayCode(int n) {
        vector<int> res;
        res.push_back(0);
        int t = 1;
        while (n -- ) {
            vector<int> newRes = res;
            // for (int i = 0; i < res.size(); i ++ )
            //     newRes.push_back(res[i]);
            for (int i = res.size() - 1; i >= 0; i -- )
                newRes.push_back(t + res[i]);
            res = newRes;
            t *= 2;
        }
        return res;
    }
};
// @lc code=end

