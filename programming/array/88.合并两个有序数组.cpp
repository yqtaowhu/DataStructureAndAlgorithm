/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   88.合并两个有序数组.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taoyanqi <taoyanqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 20:47:42 by taoyanqi          #+#    #+#             */
/*   Updated: 2024/04/17 20:47:59 by taoyanqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        while(m >=1 && n >= 1) {
            if(nums1[m-1] >= nums2[n-1]) {
                nums1[m+n-1] = nums1[m-1];
                m--;
            } else {
                nums1[m+n-1] = nums2[n-1];
                n--;
            }
        }
        while(n >= 1) {
            nums1[n-1] = nums2[n-1];
            n--;
        }
    }
};