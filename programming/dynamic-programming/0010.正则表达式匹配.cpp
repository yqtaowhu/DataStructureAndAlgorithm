/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0010.正则表达式匹配.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taoyanqi <taoyanqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 17:26:51 by taoyanqi          #+#    #+#             */
/*   Updated: 2025/10/14 17:26:54 by taoyanqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();
        vector<vector<bool>> dp(m+1, vector<bool>(n+1, false));

        dp[0][0] = true;

        // 初始化空串匹配模式
        for (int j = 2; j <= n; ++j) {
            if (p[j-1] == '*') {
                dp[0][j] = dp[0][j-2];
            }
        }

        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (p[j-1] == '.' || p[j-1] == s[i-1]) {
                    dp[i][j] = dp[i-1][j-1];
                } else if (p[j-1] == '*') {
                    // 匹配零次
                    dp[i][j] = dp[i][j-2];
                    // 一次或多次匹配：dp[i-1][j]
                    if (p[j-2] == '.' || p[j-2] == s[i-1]) {
                        dp[i][j] = dp[i][j] || dp[i-1][j];
                    }
                }
            }
        }

        return dp[m][n]; 
    }
};