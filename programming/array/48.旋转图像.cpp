/*
 * @lc app=leetcode.cn id=48 lang=cpp
 *
 * [48] 旋转图像
 */

// @lc code=start
class Solution {
public:
    // 顺时针旋转图像
    // 方法1， 转置+反转每一行，两次的矩阵操作
    void rotate_1(vector<vector<int>>& matrix) {
        int n = matrix.size();
        // 转置 
        for(int i=0; i<n; i++) {
            for(int j=i; j<n; j++) { // 注意j的写法
                swap(matrix[i][j], matrix[j][i]); // 转置定义
            }
        }
        // 反转每一行
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n / 2; j++) { // 注意j<n/2即可
                swap(matrix[i][j], matrix[i][n-1-j]);
            }
        }
    }
    // 考虑4个为一组的元素进行旋转，注意i,j的下标，画图操作
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        for (int i=0;i<n/2;i++) {
            for (int j=i;j<n-1-i;j++) {
                int z = matrix[i][j];
                matrix[i][j] = matrix[n-j-1][i];
                matrix[n-j-1][i] = matrix[n-i-1][n-j-1];
                matrix[n-i-1][n-j-1] = matrix[j][n-i-1];
                matrix[j][n-i-1] = z;
            }
        }
    }
};
// @lc code=end

