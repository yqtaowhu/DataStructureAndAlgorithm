/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0011.盛最多水的容器.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taoyanqi <taoyanqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 12:32:13 by taoyanqi          #+#    #+#             */
/*   Updated: 2025/10/15 12:32:14 by taoyanqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * @lc app=leetcode.cn id=11 lang=cpp
 *
 * [11] 盛最多水的容器
 */

// @lc code=start
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    // 双指针判断即可，简单题
    int maxArea(vector<int>& height) {
        int len = height.size();
        if(len < 2) return 0;
        int left = 0, right = len - 1, res = 0;
        while(left < right) {
            if (height[left] <= height[right]) {
                res = max(res, height[left] * (right - left));
                left++;
            } else {
                res = max(res, height[right] * (right - left));
                right--;
            }
        }
       return res; 
    }
};
// @lc code=end

