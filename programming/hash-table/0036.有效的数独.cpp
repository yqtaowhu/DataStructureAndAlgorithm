/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0036.有效的数独.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taoyanqi <taoyanqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 17:51:15 by taoyanqi          #+#    #+#             */
/*   Updated: 2025/10/27 17:51:33 by taoyanqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // row[9][9] : 第i行有数字x
        bool row[9][9] = {false}, col[9][9] = {false}, box[3][3][9] = {false};
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    int num = board[i][j] - '0' - 1;
                    if (row[i][num] || col[j][num] || box[i/3][j/3][num]) {
                        return false;
                    } 
                    row[i][num] = col[j][num] = box[i/3][j/3][num] = true;
                }
            }
        }
        return true;
    }
};