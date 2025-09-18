/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3583. 统计特殊三元组.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taoyanqi <taoyanqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 16:00:27 by taoyanqi          #+#    #+#             */
/*   Updated: 2025/09/18 16:00:27 by taoyanqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

class Solution {
public:
    // 遍历中间元素j, 看左右两边是不是有符合的元素
    // 后缀需要处理，前缀随遍历计算
    int specialTriplets(vector<int>& nums) {
        const int mod = 1e9 + 7;
        // 技巧，不需要知道每个位置的的元素后分布，只需要统计一次，遍历的时候减掉
        unordered_map<int, int> suf, pre;
        for(auto x: nums) {
            suf[x]++;
        }
        long long int ans = 0;
        for(auto x : nums) {   // 遍历中间元素
            suf[x]--;
            // 现在pre [0-j-1]  suf [j-n-1]
            ans += 1LL * pre[2*x] * suf[2*x];
            pre[x]++;
        }
        return ans % mod;
    }
};