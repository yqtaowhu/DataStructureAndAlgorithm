/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2260. 必须拿起的最小连续卡牌数.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taoyanqi <taoyanqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 09:25:06 by taoyanqi          #+#    #+#             */
/*   Updated: 2025/09/18 09:25:07 by taoyanqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

class Solution {
public:
    // 维护每个数的最后一次出现的位置
    int minimumCardPickup(vector<int>& cards) {
        int res = INT_MAX;
        unordered_map<int, int> mp;
        for(int i = 0; i < cards.size(); i++) {
            if(mp.count(cards[i])) {
                res = min(res, i - mp[cards[i]] + 1);
            }
            mp[cards[i]] = i;
        }
        return res == INT_MAX ? -1 : res;
    }
};