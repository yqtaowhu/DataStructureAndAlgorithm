/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0035.搜索插入位置.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taoyanqi <taoyanqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 17:35:20 by taoyanqi          #+#    #+#             */
/*   Updated: 2025/10/24 17:38:07 by taoyanqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

class Solution {
public:
    // 左闭右开, 其实就是找到第一个大于等于target的数，和34题一样的
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        if(n == 0) return 0;
        int left = 0, right = nums.size();
        while(left < right) {
            int mid = left + (right-left) / 2;
            if(nums[mid] < target) {
                left = mid+1;
            } else {
                right = mid;
            }
        }
        return left;
    }
};