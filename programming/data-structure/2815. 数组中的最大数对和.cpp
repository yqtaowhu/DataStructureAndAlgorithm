/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2815. 数组中的最大数对和.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taoyanqi <taoyanqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 09:26:39 by taoyanqi          #+#    #+#             */
/*   Updated: 2025/09/18 09:26:39 by taoyanqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

class Solution {
public:
    // 维护最大数位的最大值
    int help(int x) {
        int res = 0;
        while(x) {
            res = max(res, x % 10);
            x /= 10;
        }
        return res;
    }

    int maxSum(vector<int>& nums) {
        unordered_map<int, int> mp;
        int res = 0;
        for(auto x : nums) {
            // 获取最大数位
            int tmp = help(x);
            if(mp.count(tmp)) {
                res = max(res, mp[tmp] + x);
            }
            mp[tmp] = max(mp[tmp], x);
        }
        return res == 0 ? -1 : res;

        
    }
};