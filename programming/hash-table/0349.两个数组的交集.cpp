/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0349.两个数组的交集.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taoyanqi <taoyanqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/30 by taoyanqi                        #+#    #+#             */
/*   Updated: 2026/08/30 by taoyanqi                        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// 解法二：排序 + 双指针，O(1) 额外空间（不计输出），进阶要求
// 与 350 的区别：去重，相等时收集后需跳过两数组中所有重复元素
class Solution2 {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
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
                res.push_back(nums1[i]);
                // 跳过重复元素，保证结果去重
                int v = nums1[i];
                while(i < nums1.size() && nums1[i] == v) i++;
                while(j < nums2.size() && nums2[j] == v) j++;
            }
        }
        return res;
    }
};

// 349. 两个数组的交集
// 哈希集合：nums1 建集合，遍历 nums2 命中即收集并 erase，保证结果去重
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        unordered_set<int> s;
        for(auto n : nums1) {
            s.insert(n);
        }
        for(auto n : nums2) {
            if(s.contains(n)) {
                res.push_back(n);
                s.erase(n); // 已加入结果，防止 nums2 中的重复元素重复输出
            }
        }
        return res;
    }
};
