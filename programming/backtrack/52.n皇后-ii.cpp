/*
 * @lc app=leetcode.cn id=52 lang=cpp
 *
 * [52] N皇后 II
 */

// @lc code=start
class Solution {
public:

    bool valid(vector<string> &matrix, int row, int col, int n) {
        for (int i=0;i!=row;i++)               //column
            if (matrix[i][col]=='Q') return false;
        for (int i=row-1,j=col-1;i>=0&&j>=0;i--,j--)  //从当前行，列的前45度
            if (matrix[i][j]=='Q') return false;
        for (int i=row-1,j=col+1;i>=0&&j<n;i--,j++)   //135度
            if (matrix[i][j]=='Q') return false;
        return true;
    }
    // 标准的回溯算法的写法
    void backtrace(int &res, vector<string> &matrix, int n, int row) {
        // 满足条件
        if(row == n) {
            res++;
            return;
        }
        // dfs，没一行的列就是其相邻的边
        for(int col=0; col<n; col++) {
            // 判断是否满足条件
            if(valid(matrix, row, col,n)) {
                matrix[row][col] = 'Q';
                backtrace(res, matrix, n, row+1);
                matrix[row][col] = '.'; //回溯
            }
        }
    }
    int totalNQueens(int n) {
        int res=0;
        vector<string> matrix(n, string(n,'.')); // 初始化矩阵
        backtrace(res, matrix, n, 0); 
        return res;
        
    }
};
// @lc code=end

