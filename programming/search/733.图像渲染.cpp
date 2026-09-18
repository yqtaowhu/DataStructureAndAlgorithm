/*
 * @lc app=leetcode.cn id=733 lang=cpp
 *
 * [733] 图像渲染
 */

// @lc code=start
// 标准 Flood Fill（网格 DFS）。注意：新旧颜色相同时必须直接返回，
// 否则标记失效会无限递归。
class Solution {
public:
    void dfs(vector<vector<int>>& image, int i, int j, int oldColor, int newColor) {
        if (i < 0 || i >= (int)image.size() || j < 0 || j >= (int)image[0].size()
            || image[i][j] != oldColor) return;
        image[i][j] = newColor;                       // 进入即标记
        int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};
        for (int d = 0; d < 4; d++)
            dfs(image, i + dx[d], j + dy[d], oldColor, newColor);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if (image[sr][sc] == color) return image;     // 关键：同色直接返回
        dfs(image, sr, sc, image[sr][sc], color);
        return image;
    }
};
// @lc code=end
