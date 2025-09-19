/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3361.两个字符串的切换距离.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taoyanqi <taoyanqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 17:12:43 by taoyanqi          #+#    #+#             */
/*   Updated: 2025/09/19 17:12:44 by taoyanqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

class Solution {
public:
    long long shiftDistance(string s, string t, vector<int>& nextCost, vector<int>& previousCost) {
        const int SIGMA = 26;
        long long nxt_sum[SIGMA * 2 + 1]{}, pre_sum[SIGMA * 2 + 1]{};
        for (int i = 0; i < SIGMA * 2; i++) {
            nxt_sum[i + 1] = nxt_sum[i] + nextCost[i % SIGMA];
            pre_sum[i + 1] = pre_sum[i] + previousCost[i % SIGMA];
        }

        long long ans = 0;
        for (int i = 0; i < s.size(); i++) {
            int x = s[i] - 'a', y = t[i] - 'a';
            ans += min(nxt_sum[y < x ? y + SIGMA : y] - nxt_sum[x],
                       pre_sum[(x < y ? x + SIGMA : x) + 1] - pre_sum[y + 1]);
        }
        return ans;
    }
};