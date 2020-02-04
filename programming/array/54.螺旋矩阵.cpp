/*
 * @lc app=leetcode.cn id=54 lang=cpp
 *
 * [54] 螺旋矩阵
 */

// @lc code=start
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
       if(matrix.empty()) {
           return res;
       } 
       int m = matrix.size(), n=matrix[0].size();
       int left=0,right=n-1,top=0,bottom=m-1;
       // 一圈圈打印
       while(left<=right && top<=bottom) {
           //left->right
           for(int i=left; i<=right; i++) {
               res.push_back(matrix[top][i]);
           }
           // top->bottom
           for(int i=top+1; i<=bottom; i++) {
               res.push_back(matrix[i][right]);
           }
           // right -> left, 如果当前仅有一行，会重复
           if(top != bottom) {
               	for (int i = right - 1; i >= left; i--) {
				    res.push_back(matrix[bottom][i]);
                }
           }
           // bottom -> top // 可能只有一列
           if(left != right) {
               for(int i=bottom-1; i> top; i--) {
                   res.push_back(matrix[i][left]);
               }
           }
           left++,right--,top++,bottom--;
           
       }
       return res;
    }
};
// @lc code=end

