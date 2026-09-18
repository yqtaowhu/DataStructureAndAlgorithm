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
        int m = nums.size();
        if(m <= 1) return -1;
        int mx = INT_MAX, ans = -1;
        for(int j=1; j < m; j++) {
            mx = min(mx, nums[j-1]);
            if(nums[j] > mx) {
                ans = max(ans, nums[j] - mx);
            }
        }
        return ans;
        
    }
};