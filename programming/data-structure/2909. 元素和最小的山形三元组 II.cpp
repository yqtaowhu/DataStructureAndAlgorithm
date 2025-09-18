/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2909. 元素和最小的山形三元组 II.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taoyanqi <taoyanqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 15:59:03 by taoyanqi          #+#    #+#             */
/*   Updated: 2025/09/18 15:59:05 by taoyanqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

class Solution {
public:
    // i, j, k  遍历j,分别找j左边和右边的最小值
    // 前缀后缀分解
    int minimumSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> suf(n, INT_MAX);
        suf[n-1] = nums[n-1];
        for (int i = n - 2; i >= 0; i--) {
            suf[i] = min(suf[i + 1], nums[i + 1]);
        }
        int ans = INT_MAX;
        int pre = nums[0];
        for(int j=1; j < n-1; j++) {
            if(pre < nums[j] && nums[j] > suf[j]) {
                ans = min(ans, pre + nums[j] + suf[j]);
            }
            pre = min(pre, nums[j]);
        }
        return ans == INT_MAX ? -1 : ans;
    }
};