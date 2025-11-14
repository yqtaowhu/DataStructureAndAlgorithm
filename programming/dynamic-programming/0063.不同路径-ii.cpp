/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0063.不同路径-ii.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taoyanqi <taoyanqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 17:27:27 by taoyanqi          #+#    #+#             */
/*   Updated: 2025/11/13 17:28:15 by taoyanqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector f(m + 1, vector<int>(n + 1));
        f[0][1] = 1;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (obstacleGrid[i][j] == 0) {
                    f[i + 1][j + 1] = f[i][j + 1] + f[i + 1][j];
                }
            }
        }
        return f[m][n];
    }
};


class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid[0].size();
        vector<int> f(n + 1);
        f[1] = 1;
        for (auto& row : obstacleGrid) {
            for (int j = 0; j < n; j++) {
                if (row[j] == 0) {
                    f[j + 1] += f[j];
                } else {
                    f[j + 1] = 0;
                }
            }
        }
        return f[n];
    }
};


class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        auto& f = obstacleGrid[0];
        f[0] ^= 1; // 0 变成 1，1 变成 0
        for (int j = 1; j < n; j++) {
            f[j] = f[j] ? 0 : f[j - 1];
        }
        for (int i = 1; i < m; i++) {
            if (obstacleGrid[i][0]) {
                f[0] = 0;
            }
            for (int j = 1; j < n; j++) {
                if (obstacleGrid[i][j] == 0) {
                    f[j] += f[j - 1];
                } else {
                    f[j] = 0;
                }
            }
        }
        return f[n - 1];
    }
};