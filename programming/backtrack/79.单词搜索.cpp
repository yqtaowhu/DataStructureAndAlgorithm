/*
 * @lc app=leetcode.cn id=79 lang=cpp
 *
 * [79] 单词搜索
 */

// @lc code=start
class Solution {
public:
    bool dfs(vector<vector<char>>& board, string word, vector<vector<int> > &vis, int rows, int cols, int i, int j, int k) {
        // 边界条件
        if(i<0 || i>= rows || j <0 || j >= cols || board[i][j] != word[k] || vis[i][j] == 1) 
            return false;
        if(word.size() - 1 == k) return true;
        vis[i][j] = 1;
        if(dfs(board, word, vis, rows, cols, i+1, j, k+1)
            ||dfs(board, word, vis, rows, cols, i, j+1, k+1)
            ||dfs(board, word, vis, rows, cols, i-1, j, k+1)
            ||dfs(board, word, vis, rows, cols, i, j-1, k+1))
            return true;
        vis[i][j] = 0;
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
       int rows = board.size(), cols = board[0].size(), k = word.size();
       if(k==0) return true;
       if(rows == 0 || cols == 0) return false;
       vector<vector<int> > vis(rows, vector<int>(cols,0));
       for(int i=0; i < rows; i++) {
           for(int j=0; j < cols; j++) {
                if(dfs(board, word, vis, rows, cols, i, j, 0))
                    return true;
           }
       }
       return false;

    }
};
// @lc code=end

