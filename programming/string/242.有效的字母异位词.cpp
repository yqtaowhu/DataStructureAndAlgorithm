/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   242.有效的字母异位词.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taoyanqi <taoyanqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 19:37:52 by taoyanqi          #+#    #+#             */
/*   Updated: 2024/04/04 19:37:56 by taoyanqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

class Solution {
public:
    bool isAnagram(string s, string t) {
        int m = s.size(), n = t.size();
        if(m != n) return false;
        vector <int> v(26, 0);
        for(auto &c : s) {
            v[c-'a']++;
        }
        for(auto &c : t) {
            if(v[c-'a'] == 0) {
                return false;
            }
            v[c-'a']--;
        }
        return true;
    }
};