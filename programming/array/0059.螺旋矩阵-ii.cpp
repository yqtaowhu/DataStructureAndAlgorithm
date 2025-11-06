/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0059.螺旋矩阵-ii.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taoyanqi <taoyanqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 12:53:15 by taoyanqi          #+#    #+#             */
/*   Updated: 2025/11/06 12:53:21 by taoyanqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * @lc app=leetcode.cn id=59 lang=cpp
 *
 * [59] 螺旋矩阵 II
 */

// @lc code=start
class Solution {
public:
        vector<vector<int>> generateMatrix(int n) {
            vector<vector<int>> res(n,vector<int>(n,1));
            int l=0,t=0,r=n-1,b=n-1,k=1;
            while (l<=r&&t<=r) {
                for (int i=l;i<=r;i++) res[l][i]=k++;
                for (int i=t+1;i<=b;i++) res[i][r]=k++;
                if (t!=b) 
                    for (int i=r-1;i>=l;i--) res[b][i]=k++;
                if (l!=r)
                    for (int i=b-1;i>t;i--) res[i][l]=k++;
                    l++;r--;t++;b--;
            }
            return res;
        }
};
// @lc code=end

