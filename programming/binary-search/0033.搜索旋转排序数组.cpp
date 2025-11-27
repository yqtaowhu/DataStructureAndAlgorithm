/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0033.搜索旋转排序数组.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taoyanqi <taoyanqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 12:59:31 by taoyanqi          #+#    #+#             */
/*   Updated: 2025/11/27 12:42:02 by taoyanqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



// 一次二分搜索的方法

class Solution {
public:
    int search(vector<int>& nums, int target) {
        //4,5,6,7,0,1,2, 从中间进行切分后，一定有一部分是有序的
        // [l, mid] 和 [mid + 1, r] 哪个部分是有序的，
        // 并根据有序的那个部分确定我们该如何改变二分查找的上下界
        int size = nums.size();
        if(size == 0) return -1;
        if(size == 1) {
            return nums[0] == target ? 0 : -1;
        }
        int i = 0, j = size - 1;
        while(i <= j) {
            int mid = (j-i) / 2 + i;
            if (nums[mid] == target) return mid;
            // 说明左边有序
            if(nums[0] <= nums[mid]) {
                // 根据有序部分进行判断
                if(nums[0] <= target && nums[mid] > target) {
                    j = mid - 1;
                } else {
                    i = mid + 1;
                }

            } else { // 右边有序
                if(nums[mid] < target && nums[size-1] >= target) {
                    i = mid + 1;
                } else {
                    j = mid - 1;
                }
            }
        }
        return -1;
    }
};


// 两次二分搜索的方法

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
