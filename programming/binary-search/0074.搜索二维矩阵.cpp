/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0074.搜索二维矩阵.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taoyanqi <taoyanqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 12:47:19 by taoyanqi          #+#    #+#             */
/*   Updated: 2025/11/20 12:47:26 by taoyanqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// 左闭右开的模板, 左闭右开模板要在最后判断合法性，因为right初始为m*n，所以要判断left < m * n
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int left = 0, right = m * n;             // 一维总长度是 m*n
        // 找到第一个大于等于 target 的值
        while (left < right) {
            int mid = left + (right - left) / 2;
            int r = mid / n, c = mid % n;
            if (matrix[r][c] >= target) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        // left == m*n 表示所有元素都 < target
        return left < m * n && matrix[left / n][left % n] == target;
    }
};

