/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   35.搜索插入位置.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taoyanqi <taoyanqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 20:58:34 by taoyanqi          #+#    #+#             */
/*   Updated: 2024/04/19 21:03:03 by taoyanqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * @lc app=leetcode.cn id=35 lang=cpp
 *
 * [35] 搜索插入位置
 */

// @lc code=start
class Solution {
public:
    // 二分搜索，需要注意的是left,right的范围
    // 分三种情况写，然后可以在进行优化
    int searchInsert(vector<int>& nums, int target) {
        int i = 0, j =  nums.size() - 1;
        while(i <= j) {
            int mid = (i + j) / 2;
            if(nums[mid] == target) {
                i = mid;
                return i;
            } else if(nums[mid] < target) {
                i = mid + 1;
            } else {
                j = mid - 1;
            }
        }
        return i;
    }
};
// @lc code=end

