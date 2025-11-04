/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0051.n皇后.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taoyanqi <taoyanqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 11:15:11 by taoyanqi          #+#    #+#             */
/*   Updated: 2025/11/04 11:15:19 by taoyanqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

class Solution {
public:

    // 每次填一行，所以只需要看前面的行, 行不可能重复
    bool valid(int row, int col, vector<string>&tmp) {
        for(int i=0; i < row; i++) {
            // 列重复
            if(tmp[i][col] == 'Q') {
                return false;
            }
        }
        // 左上
        for(int i=row-1, j = col-1; i>=0 && j>=0; i--, j--) {
            if(tmp[i][j] == 'Q') {
                return false;
            }
        }
        // 右上
        for(int i=row-1, j = col+1; i>=0 && j<tmp.size(); i--, j++) {
            if(tmp[i][j] == 'Q') {
                return false;
            }
        }
        return true;
    }

    // 行
    void dfs(int n, vector<vector<string>> &res, vector<string>&tmp, int i) {
        if(i == n) {
            res.push_back(tmp);
            return;
        }
        // 遍历列
        for(int j=0; j < n; j++) {
            if(valid(i, j, tmp)) {
                tmp[i][j] = 'Q';
                dfs(n, res, tmp, i+1);
                tmp[i][j] = '.';
            }
        }
        return;

    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> tmp(n, string(n, '.'));
        dfs(n, res, tmp, 0);
        return res;
    }
};