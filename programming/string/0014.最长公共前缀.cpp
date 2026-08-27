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
    string longestCommonPrefix(vector<string>& strs) {
        for (int i = 0; i < strs[0].size(); i++)
            for (int j = 1; j < strs.size(); j++)
                if (i == strs[j].size() || strs[j][i] != strs[0][i])
                    return strs[0].substr(0, i);
        return strs[0];
    }
};