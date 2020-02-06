/*
 * @lc app=leetcode.cn id=74 lang=cpp
 *
 * [74] 搜索二维矩阵
 */

// @lc code=start
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // 注意判断一个矩阵为空的方法
        if(matrix.empty() || matrix[0].empty()) return false;
        int m = matrix.size(), n = matrix[0].size();
        int i=0, j = m*n - 1;
        // 使用模板二分，找左边界
        while(i<j) {
            int mid = (i+j) >> 1;
            if(matrix[mid/n][mid%n] >= target) {
                j = mid;        
            } else {
                i = mid+1;
            }
        }
        return matrix[i/n][i%n] == target;    
    }
};
// @lc code=end

