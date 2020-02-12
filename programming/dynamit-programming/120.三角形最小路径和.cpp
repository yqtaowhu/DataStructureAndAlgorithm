/*
 * @lc app=leetcode.cn id=120 lang=cpp
 *
 * [120] 三角形最小路径和
 */

// @lc code=start
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if(triangle.size() <=0 || triangle[0].size() <= 0 ) {
            return 0;
        }
        int m = triangle.size();
        for(int i=m-2; i>=0; i--) {
            for(int j=0; j<=i; j++) {
                triangle[i][j] = min(triangle[i+1][j], triangle[i+1][j+1]) + triangle[i][j];
            }
        }
        return triangle[0][0];
    }
};
// @lc code=end

