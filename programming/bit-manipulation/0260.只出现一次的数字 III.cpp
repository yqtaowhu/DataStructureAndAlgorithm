/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0260.只出现一次的数字 III.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taoyanqi <taoyanqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 12:45:40 by taoyanqi          #+#    #+#             */
/*   Updated: 2025/10/13 12:45:40 by taoyanqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        // 将所有值异或后a^b单独出现的，然后找到lowbit
        unsigned int xor_all = 0;
        for (int x : nums) {
            xor_all ^= x;
        }
        int lowbit = xor_all & -xor_all; // 用来区分元素在哪一组

        vector<int> ans(2);
        for (int x : nums) {
            if ((x & lowbit) == 0) { // x 在第一组
                ans[0] ^= x;
            } else { // x 在第二组
                ans[1] ^= x;
            }
        }
        return ans;
    }
};