/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0080.删除排序数组中的重复项.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taoyanqi <taoyanqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 12:47:06 by taoyanqi          #+#    #+#             */
/*   Updated: 2025/11/26 12:47:24 by taoyanqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

class Solution {
public:
    // 同26题一起比较
    int removeDuplicates(vector<int>& nums) {
        int size = nums.size();
        if(size <= 2) return size;
        int l = 2, r = 2;
        while(r < size) {
            // 只用这种方式避免了计数
            if(nums[r] != nums[l-2]) {
                nums[l++] = nums[r];
            }
            r++;
        }
        return l;
        
    }
};