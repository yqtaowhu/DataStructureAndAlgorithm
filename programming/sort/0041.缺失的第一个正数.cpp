/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0041.缺失的第一个正数.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taoyanqi <taoyanqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 09:35:26 by taoyanqi          #+#    #+#             */
/*   Updated: 2025/10/29 09:19:42 by taoyanqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

class Solution {
public:
    // o(n) , 桶排序
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for(int i=0; i < n; i++) {
            // 必须写成nums[i] != i + 1, 如果写成nums[i]-1!=i 则会超出边界
            while(nums[i] > 0 && nums[i] <= n && nums[i] != i + 1 && nums[i] != nums[nums[i]-1]) {
                swap(nums[i], nums[nums[i]-1]);
            }
        }
        for(int i=0; i < n; i++) {
            if(nums[i] != i+1) {
                return i+1;
            }
        }
        return n+1;
    }
};