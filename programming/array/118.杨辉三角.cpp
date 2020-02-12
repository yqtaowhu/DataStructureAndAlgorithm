/*
 * @lc app=leetcode.cn id=118 lang=cpp
 *
 * [118] 杨辉三角
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int> > res;
        if(numRows <=0) return res;
        for(int i=0; i<numRows; i++) {
            vector<int> v(i+1, 1);
            for(int j=1; j<i; j++) {
                v[j] = res[i-1][j-1] + res[i-1][j];
            }
            res.push_back(v);
        }
        return res;
    }
};
// @lc code=end

