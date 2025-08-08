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
        // 只要有一个是true就返回true
        if(dfs(board, word, vis, rows, cols, i+1, j, k+1)
            ||dfs(board, word, vis, rows, cols, i, j+1, k+1)
            ||dfs(board, word, vis, rows, cols, i-1, j, k+1)
            ||dfs(board, word, vis, rows, cols, i, j-1, k+1))
            return true;
        // 注意回溯
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

class Solution {
public:
    vector<vector<int>> dirs = {{0,1}, {0,-1}, {1, 0}, {-1, 0}};
    vector<vector<int>> visit;
 
    bool existWord(vector<vector<char>>& board, string word, int cur, int nx, int ny){
        if(cur == word.size() - 1){
            return true;
        }

        int row = board.size(), col = board[0].size();

        visit[nx][ny] = 1;
        for(const auto& dir : dirs){
            // 不要修改传进来的 nx, ny
            int x = nx + dir[0];
            int y = ny + dir[1];
            if(x >= 0 && x < row && y >= 0 && y < col && visit[x][y] == 0 && board[x][y] == word[cur+1]){
                bool flag = existWord(board, word, cur+1, x, y);
                if(flag)
                    return true;
            }
        }
        visit[nx][ny] = 0;

        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int row = board.size(), col = board[0].size();
        visit.resize(row, vector<int>(col, 0));

        for(int i = 0;i < row;i++){
            for(int j = 0;j < col;j++){
                if(board[i][j] == word[0]){
                    if(existWord(board, word, 0, i, j))
                        return true;
                }
            }
        }

        return false;
    }
};