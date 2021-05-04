/*
 * @lc app=leetcode.cn id=62 lang=cpp
 *
 * [62] 不同路径
 */

// @lc code=start
// 要了解如何优化
class Solution {
public:
     int uniquePaths(int m, int n) {
        vector<vector<int> > path(m, vector<int> (n, 1));
        for (int i = 1; i < m; i++)
            for (int j = 1; j < n; j++)
                path[i][j] = path[i - 1][j] + path[i][j - 1];
        return path[m - 1][n - 1];
    }
};
//optimize o(n),滚动数组进行优化
class Solution {
    int uniquePaths(int m, int n) {
        if (m > n) return uniquePaths(n, m); 
        vector<int> pre(m, 1);
        vector<int> cur(m, 1);
        for (int j = 1; j < n; j++) {
            for (int i = 1; i < m; i++)
                cur[i] = cur[i - 1] + pre[i];
            swap(pre, cur);
        }
        return pre[m - 1];
    }
};
//optimize
class Solution {
    int uniquePaths(int m, int n) {
        if (m > n) return uniquePaths(n, m);
        vector<int> cur(m, 1);
        for (int j = 1; j < n; j++)
            for (int i = 1; i < m; i++)
                cur[i] += cur[i - 1]; 
        return cur[m - 1];
    }
}; 
// 数学方法
//从左上角到右下角的过程中，我们需要移动 m+n-2m+n−2 次，其中有 m-1m−1 次向下移动，n-1n−1 次向右移动。因此路径的总数，就等于从 m+n-2m+n−2 次移动中选择 m-1m−1 次向下移动的方案数，即组合数：
class Solution {
public:
    int uniquePaths(int m, int n) {
        long long ans = 1;
        for (int x = n, y = 1; y < m; ++x, ++y) {
            ans = ans * x / y;
        }
        return ans;
    }
};
// @lc code=end

