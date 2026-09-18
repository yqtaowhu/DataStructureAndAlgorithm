/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0350.两个数组的交集-ii.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taoyanqi <taoyanqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/30 by taoyanqi                        #+#    #+#             */
/*   Updated: 2026/08/30 by taoyanqi                        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// 350. 两个数组的交集 II
// 与 349 不同：结果需保留重复元素次数（取两数组出现次数的较小值）
// 解法一：哈希表计数，O(m+n) 时间
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        // 用较短的数组建表，减少空间
        if(nums1.size() > nums2.size()) return intersect(nums2, nums1);
        unordered_map<int, int> cnt;
        for(auto n : nums1) cnt[n]++;
        vector<int> res;
        for(auto n : nums2) {
            if(cnt[n]-- > 0) { // 还有剩余次数才收集
                res.push_back(n);
            }
        }
        return res;
    }
};

// 解法二：排序 + 双指针，O(1) 额外空间（不计输出），进阶要求
class Solution2 {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        vector<int> res;
        int i = 0, j = 0;
        while(i < nums1.size() && j < nums2.size()) {
            if(nums1[i] < nums2[j]) {
                i++;
            } else if(nums1[i] > nums2[j]) {
                j++;
            } else {
                res.push_back(nums1[i]); // 相等即收集，双指针各前进一格，天然处理重复次数
                i++; j++;
            }
        }
        return res;
    }
};
