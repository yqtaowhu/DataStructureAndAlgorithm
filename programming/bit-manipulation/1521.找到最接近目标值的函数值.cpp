/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1521.找到最接近目标值的函数值.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taoyanqi <taoyanqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 11:13:12 by taoyanqi          #+#    #+#             */
/*   Updated: 2025/10/11 11:13:13 by taoyanqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

class Solution {
public:
    int closestToTarget(vector<int>& arr, int target) {
        int size = arr.size();
        int ans = INT_MAX;
        for(int i = 0; i < size; i++) {
            int tmp = arr[i];
            ans = min(ans, abs(tmp - target));
            // 逆序, nums[j] & tmp == nums[j] 如果增加了tmpm没有变大，则不需要再计算了
            for(int j=i-1; j>=0 && (arr[j] & tmp) != arr[j]; j--) {
                arr[j] &= tmp;
                ans = min(ans, abs(arr[j] - target));
            }
        }
        return ans;
    }
};