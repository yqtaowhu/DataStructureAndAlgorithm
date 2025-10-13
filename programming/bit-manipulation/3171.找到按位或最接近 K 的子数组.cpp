/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3171.找到按位或最接近 K 的子数组.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taoyanqi <taoyanqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 11:10:12 by taoyanqi          #+#    #+#             */
/*   Updated: 2025/10/11 11:10:41 by taoyanqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int size = nums.size();
        int ans = INT_MAX;
        for(int i = 0; i < size; i++) {
            int tmp = nums[i];
            ans = min(ans, abs(tmp - k));
            // 逆序, nums[j] & tmp == nums[j] 如果增加了tmpm没有变大，则不需要再计算了
            for(int j=i-1; j>=0 && (nums[j] | tmp) != nums[j]; j--) {
                nums[j] |= tmp;
                ans = min(ans, abs(nums[j] - k));
            }
        }
        return ans;
    }
};