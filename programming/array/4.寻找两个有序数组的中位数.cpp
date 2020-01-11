/*
 * @lc app=leetcode.cn id=4 lang=cpp
 *
 * [4] 寻找两个有序数组的中位数
 */

// @lc code=start
#include <vector>
#include <iostream>
using namespace std;


class Solution {
public:
		/*
		double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
			// 解法1， 合并两个数组，两个有序数据合并-- 归并排序，然后根据奇偶数进行判断
			// 时间复杂度：遍历全部数组 (m+n)(m+n)
				int m= nums1.size(), n = nums2.size();
				if(m < n) return findMedianSortedArrays(nums2, nums1); // 技巧，只需考虑m>n情况
				if(n == 0) {
						// 技巧，不需要分奇偶数，思考?
						return (nums1[(m-1)/2] + nums1[m/2]) / 2.0;
				}
				vector<int> nums(m+n);
				int i = 0,j = 0, k = 0;
				while(i < m && j < n) {
					if(nums1[i] <= nums2[j]) {
							nums[k++] = nums1[i++];
					} else {
							nums[k++] = nums2[j++];
					}
				}
				while(i < m) {
					nums[k++] = nums1[i++];
				}
				while(j < n) {
					nums[k++] = nums2[j++];
				}
				return (nums[(k-1)/2] + nums[k/2]) / 2.0;
		}
		*/
		/*
			解法2: 对两个数据进行划分，填补#
			#1#2#4#7
			#3#4#5
		*/
		double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
            int m = nums1.size(), n = nums2.size();
            if(m < n) return findMedianSortedArrays(nums2, nums1);
            if(n == 0) {
                return (nums1[(m-1)/2] + nums1[m/2]) / 2.0;
            }
            int left = 0, right = 2 * n;
            // 对段的数组进行二分, 保证 mid1 + mid2 = (m + n)/2, 因为数组都填充了 所以是m+n
            while(left <= right) {
                int mid2 = (left + right) / 2;
                int mid1 = m + n - mid2;   
                double L1 = (mid1 == 0) ? INT_MIN : nums1[(mid1 - 1) / 2];	// Get L1, R1, L2, R2 respectively
		        double L2 = (mid2 == 0) ? INT_MIN : nums2[(mid2 - 1) / 2];
		        double R1 = (mid1 == m * 2) ? INT_MAX : nums1[(mid1) / 2];
		        double R2 = (mid2 == n * 2) ? INT_MAX : nums2[(mid2) / 2];
                if(L1 > R2) left = mid2 + 1;
                else if(L2 > R1) right = mid2 - 1;
                else return (max(L1, L2) + min(R1, R2)) / 2;
            }
            return -1;
		}
};
// @lc code=end

/* 解法三：递归方法
参考：https://www.acwing.com/solution/LeetCode/content/50/

在两个有序数组中，找出第k小数?

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int total = nums1.size() + nums2.size();
        if (total % 2 == 0)
        {
            int left = findKthNumber(nums1, 0, nums2, 0, total / 2);
            int right = findKthNumber(nums1, 0, nums2, 0, total / 2 + 1);
            return (left + right) / 2.0;
        }
        else
        {
            return findKthNumber(nums1, 0, nums2, 0, total / 2 + 1);
        }
    }

    int findKthNumber(vector<int> &nums1, int i, vector<int> &nums2, int j, int k)
    {
        if (nums1.size() - i > nums2.size() - j) return findKthNumber(nums2, j, nums1, i, k);
        if (nums1.size() == i) return nums2[j + k - 1];
        if (k == 1) return min(nums1[i], nums2[j]);
        int si = min(i + k / 2, int(nums1.size())), sj = j + k / 2;
        if (nums1[si - 1] > nums2[sj - 1])
        {
            return findKthNumber(nums1, i, nums2, j + k / 2, k - k / 2);
        }
        else
        {
            return findKthNumber(nums1, si, nums2, j, k - (si - i));
        }
    }
};
*/