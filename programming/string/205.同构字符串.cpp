/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   205.同构字符串.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taoyanqi <taoyanqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 20:56:08 by taoyanqi          #+#    #+#             */
/*   Updated: 2024/04/09 20:56:09 by taoyanqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// 双射问题，两个哈希表
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int m = s.size(), n = t.size();
        if(m !=n ) return false;
        if(m == 0) return true;
        unordered_map<char, char> s2t, t2s;
        for(int i=0; i < m; i++) {
            char x = s[i], y = t[i];
            if(s2t.count(x) && s2t[x] != y) {
                return false;
            }
            if(t2s.count(y) && t2s[y] != x) {
                return false;
            }
            s2t[x] = y;
            t2s[y] = x;
        }
        return true;
    }
};