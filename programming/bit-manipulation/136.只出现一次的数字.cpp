/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   136.只出现一次的数字.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taoyanqi <taoyanqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 20:48:40 by taoyanqi          #+#    #+#             */
/*   Updated: 2024/04/11 20:48:41 by taoyanqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * @lc app=leetcode.cn id=136 lang=cpp
 *
 * [136] 只出现一次的数字
 */

// @lc code=start
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for(auto &n:nums) {
            res ^= n;
        }
        return res;
    }
};
// @lc code=end

