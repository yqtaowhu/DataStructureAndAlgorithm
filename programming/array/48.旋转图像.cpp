/*
 * @lc app=leetcode.cn id=48 lang=cpp
 *
 * [48] 旋转图像
 */

// @lc code=start
class Solution {
public:
    // 顺时针旋转图像
    // 方法1:转置+反转每一行，两次的矩阵操作
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
    // 方法2:考虑4个为一组的元素进行旋转，注意i,j的下标，画图操作
    void rotate(vector<vector<int>>& matrix) {
        if(matrix.empty() || matrix[0].empty()) {
            return;
        }
        int n = matrix.size();
        // i是圈圈的次数 n/2, j=i开始， j<n-i-1
        for(int i=0; i < n/ 2; i++) {
            for(int j = i; j < n-i-1; j++) {    
                int z = matrix[i][j];
                matrix[i][j] = matrix[n-1-j][i];  // 00 = 30 01 = 20
                matrix[n-1-j][i] = matrix[n-1-i][n-j-1]; // 30 = 33 20 = 32
                matrix[n-1-i][n-1-j] = matrix[j][n-1-i]; // 33 = 03  32 = 13
                matrix[j][n-1-i] = z;
            }
        }
    }
};
// @lc code=end

