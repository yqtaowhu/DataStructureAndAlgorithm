/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   22.括号生成.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taoyanqi <taoyanqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 12:54:14 by taoyanqi          #+#    #+#             */
/*   Updated: 2025/10/16 12:54:21 by taoyanqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// 本质上来说，我们需要在 0,1,2,…,2n−1 中选 n 个数（位置），填入左括号。其余 n 位置填入右括号。
class Solution {
public:
    vector<string> res;

    void dfs(int n, int left, int right, string &path) {
        if(right == n) {
            res.push_back(path);
            return;
        }
        // 选哪个
        if(left < n) {
            path[left+right] = '(';
            dfs(n, left+1, right, path);
        }
        if(right < left) {
            path[left+right] = ')';
            dfs(n, left, right+1, path);
        }
    }
    vector<string> generateParenthesis(int n) {
        string path(2*n, 0);
        dfs(n, 0, 0, path);
        return res;
    }
};

