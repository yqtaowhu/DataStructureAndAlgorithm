/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2016. 增量元素之间的最大差值.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taoyanqi <taoyanqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 09:23:34 by taoyanqi          #+#    #+#             */
/*   Updated: 2025/09/18 09:23:35 by taoyanqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int size = nums.size();
        if(size < 2) return -1;
        int min_v = nums[0], res = INT_MIN;
        for(int i=1; i<size; i++) {
            if(nums[i] > min_v) {
                res = max(res, nums[i] - min_v);
            } else {
                min_v = nums[i];
            }
        }
        return res == INT_MIN ? -1 : res;
        
    }
};