/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   169.多数元素.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taoyanqi <taoyanqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 20:56:56 by taoyanqi          #+#    #+#             */
/*   Updated: 2024/04/10 20:57:13 by taoyanqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

class Solution {
public:
    // 投票算法
    int majorityElement(vector<int>& nums) {
        int candidate = -1;
        int count = 0;
        for (int num : nums) {
            if (num == candidate)
                ++count;
            else if (--count < 0) {
                candidate = num;
                count = 1;
            }
        }
        return candidate;
    }
};