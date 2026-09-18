/*
 * @lc app=leetcode.cn id=417 lang=cpp
 *
 * [417] 太平洋大西洋水流问题
 */

// @lc code=start
// 逆向思维：不是从每个点判断能否流到两洋，而是从两洋边界"往高处"淹没，
// 最后两片淹没区的交集就是答案。
class Solution {
public:
    int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};
    // 从 (i,j) 出发，只往"更高或等高"的格子扩散
    void dfs(vector<vector<int>>& h, vector<vector<bool>>& vis, int i, int j) {
        vis[i][j] = true;
        for (int d = 0; d < 4; d++) {
            int x = i + dx[d], y = j + dy[d];
            if (x < 0 || x >= (int)h.size() || y < 0 || y >= (int)h[0].size()
                || vis[x][y] || h[x][y] < h[i][j]) continue;
            dfs(h, vis, x, y);
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();
        vector<vector<bool>> pac(m, vector<bool>(n, false));
        vector<vector<bool>> atl(m, vector<bool>(n, false));
        // 太平洋：左边界 + 上边界；大西洋：右边界 + 下边界
        for (int i = 0; i < m; i++) { dfs(heights, pac, i, 0); dfs(heights, atl, i, n - 1); }
        for (int j = 0; j < n; j++) { dfs(heights, pac, 0, j); dfs(heights, atl, m - 1, j); }
        vector<vector<int>> ans;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (pac[i][j] && atl[i][j]) ans.push_back({i, j});
        return ans;
    }
};
// @lc code=end
