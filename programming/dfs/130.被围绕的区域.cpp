/*
 * @lc app=leetcode.cn id=130 lang=cpp
 *
 * [130] 被围绕的区域
 */

// @lc code=start
class Solution {
public:
    // 逆向思维，从边界处，遍历O，将相邻的O置为true
    // 将false置为X

    int m, n;
    void solve(vector<vector<char>>& board) {
        if(board.empty()) return;
        m=board.size();
        n=board[0].size();
        vector<vector<int> > visit(m, vector<int>(n,0));
        // 行
        for(int i=0; i<n; i++) {
            if(board[0][i] == 'O') dfs(0, i, board, visit);
            if(board[m-1][i] == 'O') dfs(m-1, i, board, visit);   
        }
        // 列
        for(int i=0; i<m; i++) {
            if(board[i][0] == 'O') dfs(i, 0, board, visit);
            if(board[i][n-1] == 'O') dfs(i, n-1, board, visit);
        }
        // 填充
        for (int i = 0; i < m; i ++ )
            for (int j = 0; j < n; j ++ )
                if (!visit[i][j])
                    board[i][j] = 'X';
    }
    
    void dfs(int x, int y, vector<vector<char> > &board, vector<vector<int> > &visit) {
        visit[x][y] = 1;
        int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
        for(int i=0; i<4; i++) {
            int a = x+dx[i], b = y+dy[i];
            if(a>=0 && a<m && b>=0 && b<n && !visit[a][b] && board[a][b] == 'O') {
                dfs(a, b, board, visit);
            }
        }
    }
};
// @lc code=end

