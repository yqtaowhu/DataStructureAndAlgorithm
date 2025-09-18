/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2342. 数位和相等数对的最大和.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taoyanqi <taoyanqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 09:28:00 by taoyanqi          #+#    #+#             */
/*   Updated: 2025/09/18 09:28:01 by taoyanqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

class Solution {
public:
    // 维护数位和
    int help(int x) {
        int res = 0;
        while(x) {
            res += x % 10;
            x /= 10;
        }
        return res;
    }

    int maximumSum(vector<int>& nums) {
        int res = INT_MIN;
        unordered_map<int, int> mp;
        for(auto x : nums) {
            int tmp = help(x);
            // 找到相同的数位和
            if(mp.count(tmp)) {
                res = max(res, mp[tmp] + x);
            }
            mp[tmp] = max(mp[tmp], x); // 更新数位和相同的最大值
        }
        return res == INT_MIN ? -1 : res;
        
    }
};