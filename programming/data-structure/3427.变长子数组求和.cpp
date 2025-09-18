/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3427.变长子数组求和.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taoyanqi <taoyanqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 16:18:36 by taoyanqi          #+#    #+#             */
/*   Updated: 2025/09/18 16:18:36 by taoyanqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

class Solution {
public:
    int subarraySum(vector<int>& nums) {
        int n = nums.size();
        vector<int> pre_sum(n+1,0);
        for(int i=0; i < n; i++) {
            pre_sum[i+1] = pre_sum[i] + nums[i];
        }
        int res = 0;
        for(int i=0; i < n; i++) {
            int idx = max(0, i - nums[i]);
            res += pre_sum[i+1] - pre_sum[idx];
            //cout << idx << " " << res << endl;

        }
        return res;
    }
};