/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0004.寻找两个有序数组的中位数.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taoyanqi <taoyanqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 17:10:47 by taoyanqi          #+#    #+#             */
/*   Updated: 2025/10/14 17:10:47 by taoyanqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        // 保证 nums1 是较短的数组
        if (m > n) {
            return findMedianSortedArrays(nums2, nums1);
        }

        int left = 0, right = m;
        int totalLeft = (m + n + 1) / 2; // 左半部分总长度

        while (left <= right) {
            int i = left + (right - left) / 2; // nums1 切分位置
            int j = totalLeft - i;             // nums2 切分位置

            int nums1LeftMax = (i == 0) ? INT_MIN : nums1[i - 1];
            int nums1RightMin = (i == m) ? INT_MAX : nums1[i];
            int nums2LeftMax = (j == 0) ? INT_MIN : nums2[j - 1];
            int nums2RightMin = (j == n) ? INT_MAX : nums2[j];

            if (nums1LeftMax <= nums2RightMin && nums2LeftMax <= nums1RightMin) {
                // 找到正确切分
                if ((m + n) % 2 == 1) {
                    return max(nums1LeftMax, nums2LeftMax);
                } else {
                    return (max(nums1LeftMax, nums2LeftMax) + min(nums1RightMin, nums2RightMin)) / 2.0;
                }
            } else if (nums1LeftMax > nums2RightMin) {
                // i 太大，往左移
                right = i - 1;
            } else {
                // i 太小，往右移
                left = i + 1;
            }
        }
        return 0.0;
    }
};