/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0026.删除排序数组中的重复项.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taoyanqi <taoyanqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 17:55:30 by taoyanqi          #+#    #+#             */
/*   Updated: 2025/11/26 12:44:08 by taoyanqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * @lc app=leetcode.cn id=26 lang=cpp
 *
 * [26] 删除排序数组中的重复项
 */

// @lc code=start
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int size = nums.size();
        if(size < 2) return size;
        // l 是待修改项，r是遍历位置
        int l = 1, r = 1;
        while(r < size) {
            if(nums[r] != nums[l-1]) {
                nums[l++] = nums[r];
            }
            r++;
        }
        return l;
    }
};
// @lc code=end

