/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1128. 等价多米诺骨牌对的数量.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taoyanqi <taoyanqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 09:22:42 by taoyanqi          #+#    #+#             */
/*   Updated: 2025/09/18 09:22:43 by taoyanqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        int res = 0;
        unordered_map<int, int> m;
        for(auto& domino: dominoes) {
            int key = (domino[0] < domino[1] ? domino[0] * 10 + domino[1] : domino[1] * 10 + domino[0]);
            res += m[key];
            m[key]++;
        }
        return res;
    }
};