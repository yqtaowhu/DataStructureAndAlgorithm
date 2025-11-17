/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0072.编辑距离.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taoyanqi <taoyanqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 09:31:41 by taoyanqi          #+#    #+#             */
/*   Updated: 2025/11/17 09:31:42 by taoyanqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * @lc app=leetcode.cn id=72 lang=cpp
 *
 * [72] 编辑距离
 */

// @lc code=start
class Solution {
public:
    int minDistance(string word1, string word2) {
        // dp 
        int m = word1.size(), n =word2.size();
        vector<vector<int> > dp(m+1, vector<int>(n+1,0));
        //初始化
        for(int i=1; i<=m; i++) {
            dp[i][0] = i;
        }
        for(int i=1; i<=n; i++) {
            dp[0][i] = i;
        }
        for(int i=1; i<=m; i++) {
            for(int j=1; j<=n; j++) {
                if(word1[i-1] == word2[j-1]) {
                    dp[i][j] = dp[i-1][j-1];
                } else {
                    dp[i][j] = min(dp[i-1][j-1], min(dp[i][j-1], dp[i-1][j])) + 1;
                }
            }
        }
        return dp[m][n];
        
    }
};
// @lc code=end

