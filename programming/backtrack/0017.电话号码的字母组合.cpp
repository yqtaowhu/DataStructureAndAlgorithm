/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0017.电话号码的字母组合.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taoyanqi <taoyanqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 12:49:40 by taoyanqi          #+#    #+#             */
/*   Updated: 2025/10/15 12:49:41 by taoyanqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

class Solution {
public:
    const string MAPPING[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> res;

    void dfs(string digits, string &tmp, int i) {
        if(i == digits.size()) {
            res.push_back(tmp);
            return;
        }
        //for(int i=beg;i < MAPPING[digits[i]].size(); i++) {
        for (auto c : MAPPING[digits[i] - '0']) {
            //cout << "1: " << c << endl;
            tmp.push_back(c);
            dfs(digits, tmp, i+1);
            tmp.pop_back();
            // if (!tmp.empty()) {
            //     cout << "2: " << tmp[tmp.size()-1] << endl;
            // }
            
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return res;
        string tmp;
        dfs(digits, tmp, 0);
        return res;
        
    }
};


class Solution {
    const string MAPPING[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

public:
    vector<string> letterCombinations(string digits) {
        int n = digits.length();
        if (n == 0) {
            return {};
        }
        vector<string> ans;
        string path(n, 0); // 注意 path 长度一开始就是 n，不是空串
        auto dfs = [&](this auto&& dfs, int i) {
            if (i == n) {
                ans.emplace_back(path);
                return;
            }
            for (char c : MAPPING[digits[i] - '0']) {
                path[i] = c; // 直接覆盖
                dfs(i + 1);
            }
        };
        dfs(0);
        return ans;
    }
};
