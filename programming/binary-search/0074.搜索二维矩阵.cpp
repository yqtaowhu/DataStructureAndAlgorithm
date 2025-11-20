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

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty() || matrix[0].empty()) return false;
        int m = matrix.size(), n = matrix[0].size();
        int left=0, right = m*n-1;
        while(left <= right) {
            int mid = (right-left) / 2 + left;
            int r = mid / n, c = mid % n;
            if(matrix[r][c] == target) {
                return true;
            } else if(matrix[r][c] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return false;
        
    }
};

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // 注意判断一个矩阵为空的方法
        if(matrix.empty() || matrix[0].empty()) return false;
        int m = matrix.size(), n = matrix[0].size();
        int i=0, j = m*n - 1;
        // 使用模板二分，找左边界
        while(i<j) {
            int mid = (i+j) >> 1;
            if(matrix[mid/n][mid%n] >= target) {
                j = mid;        
            } else {
                i = mid+1;
            }
        }
        return matrix[i/n][i%n] == target;    
    }
};

