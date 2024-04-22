/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   27.移除元素.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taoyanqi <taoyanqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 20:41:17 by taoyanqi          #+#    #+#             */
/*   Updated: 2024/04/22 20:41:21 by taoyanqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * @lc app=leetcode.cn id=27 lang=cpp
 *
 * [27] 移除元素
 */

// @lc code=start
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int m = nums.size();
        if(m == 0) return 0;
        int end = 0;
        for(int i=0; i < m; i++) {
            if(nums[i] != val) {
                nums[end] = nums[i];
                end++;
            }
        }
        return end;
    }
};
// @lc code=end

