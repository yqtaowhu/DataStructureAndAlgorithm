/*
 * @lc app=leetcode.cn id=73 lang=cpp
 *
 * [73] 矩阵置零
 */

// @lc code=start
class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        int rows = matrix.size(), cols = matrix[0].size();
        // 使用两个数组记录0的行，列
        vector<int> r(rows,0),c(cols,0);
        for (int i=0;i<rows;i++) {
            for (int j=0;j<cols;j++) {
                if (matrix[i][j]==0) {
                    r[i]=1;
                    c[j]=1;
                }
            }
        }
        // 如果当前位置行列不为0，则将其赋值为0
        for (int i=0;i<rows;i++) {
            for (int j=0;j<cols;j++) {
                if (r[i]||c[j])
                    matrix[i][j]=0;
            }
        }
    }
};

/*
class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        int m = matrix.size();  
        int n = matrix[0].size();  
        int i, j;  
          
        //先标记第一行和第一列是否有0  
        bool firstRow = false, firstCol = false;  
        for (j = 0; j < n; j++) {  
            if (0 == matrix[0][j]) {  
                firstRow = true;  
                break;  
            }  
        }  
        for (i = 0; i < m; i++) {  
            if (0 == matrix[i][0]) {  
                firstCol = true;  
                break;  
            }  
        }  
           
        //从第二行第二列还是遍历，如果遇到0，则把它所在行和列的第一个值设为0     
        for (i = 1; i < m; i++) {  
            for (j = 1; j < n; j++) {  
                if (0 == matrix[i][j]) {  
                    matrix[i][0] = 0;  
                    matrix[0][j] = 0;  
                }  
            }  
        }  
          
        //把第一列的0所在行都设为0，把第一行的0所在列都设为0  
        for (i = 1; i < m; i++) {  
            if (0 == matrix[i][0]) {  
                for (j = 1; j < n; j++) {  
                    matrix[i][j] = 0;  
                }  
            }  
        }  
        for (j = 1; j < n; j++) {  
            if (0 == matrix[0][j]) {  
                for (i = 1; i < m; i++) {  
                    matrix[i][j] = 0;  
                }  
            }  
        }  
          
        //根据标记决定第一行和第一列是否全设为0  
        if (firstRow) {  
            for (j = 0; j < n; j++) {  
                matrix[0][j] = 0;  
            }  
        }  
        if (firstCol) {  
            for (i = 0; i < m; i++) {  
                matrix[i][0] = 0;  
            }  
        }  
};
*/
// @lc code=end

