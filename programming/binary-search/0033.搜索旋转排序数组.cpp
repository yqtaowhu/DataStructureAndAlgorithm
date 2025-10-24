/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0033.搜索旋转排序数组.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taoyanqi <taoyanqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 12:59:31 by taoyanqi          #+#    #+#             */
/*   Updated: 2025/10/24 12:59:34 by taoyanqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

class Solution {
public:
    // 搜索最小值位置
    int help(vector<int>& nums) {
        int left =0, right = nums.size()-1;
        while(left < right) {
            int mid = left + (right-left) / 2;
            if(nums[mid] <= nums[right]) {
                right = mid;
            } else {
                left = mid+1;
            }
        }
        return left;
    }

    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = help(nums);
        //cout << low << endl;
        int left = 0, right = n -1;
        while(left <= right) {
            int mid = left + (right-left) / 2;
            int r_mid = (mid + low) % n;
            //cout << mid << " " << r_mid << endl;
            if(nums[r_mid] == target) {
                return r_mid;
            } else if(nums[r_mid] < target) {
                left = mid+1;
            } else {
                right = mid-1;
            }
        }
        return -1;
        
    }
};