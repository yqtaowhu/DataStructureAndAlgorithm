/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3097. 或值至少为 K 的最短子数组 II.cpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taoyanqi <taoyanqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 11:14:40 by taoyanqi          #+#    #+#             */
/*   Updated: 2025/10/11 11:14:41 by taoyanqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int size = nums.size();
        int res = INT_MAX;
        for (int i = 0; i < size; i++) { 
            int x = nums[i];
            // 特殊判断
            if(x >= k) {
                return 1;
            }
            // 能够继续增大
            for(int j = i-1; j >= 0 && (nums[j] | x) != nums[j]; j--) {
                nums[j] |= x;
                if(nums[j] >= k) {
                    res = min(res, i - j + 1);
                    break;
                }
            }
        }
        return res == INT_MAX ? -1 : res;
    }
};