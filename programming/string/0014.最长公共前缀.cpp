/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   14.最长公共前缀.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taoyanqi <taoyanqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 12:38:53 by taoyanqi          #+#    #+#             */
/*   Updated: 2025/10/15 12:38:54 by taoyanqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

class Solution {
public:
    // 需要正确使用substr(0, len)
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()) return "";
        int min_len = INT_MAX;
        for(const auto& str : strs) {
            int size = str.size();
            min_len = min(size, min_len);
        }
        // 只需要比较第i位字符是不是相同
        for(int i=0; i < min_len; i++) {
            char s = strs[0][i];
            for(int j=1; j < strs.size(); j++) {
                if(strs[j][i] != s) {
                    return strs[0].substr(0, i);
                }
            }
        }
        return strs[0].substr(0, min_len);
        
    }
};