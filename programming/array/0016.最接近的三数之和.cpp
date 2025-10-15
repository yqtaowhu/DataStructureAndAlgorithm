/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   16.最接近的三数之和.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taoyanqi <taoyanqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 12:46:43 by taoyanqi          #+#    #+#             */
/*   Updated: 2025/10/15 12:46:45 by taoyanqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int size = nums.size();
        if(size < 3) return 0;
        sort(nums.begin(), nums.end());
        int min_value = INT_MAX, min_sum = 0;
        for(int i=0; i < size-2; i++) {
            int j = i+1, k = size-1, a = nums[i];
            while(j < k) {
                int b = nums[j], c = nums[k];
                int sum = a+b+c;
                if(sum == target) {
                    return sum;
                }
                if(sum > target) {
                    k--;
                } else {
                    j++;
                }
                if (abs(sum-target) < min_value) {
                    min_value = abs(sum-target);
                    min_sum = sum;

                }
            }
        }
        return min_sum;
    }
};