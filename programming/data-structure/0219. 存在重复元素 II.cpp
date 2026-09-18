/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0219. 存在重复元素 II.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taoyanqi <taoyanqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 09:24:33 by taoyanqi          #+#    #+#             */
/*   Updated: 2025/09/18 09:24:33 by taoyanqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// 219. 存在重复元素 II
// 模板：定长窗口（入 → 更新 → 出），窗口内最多保留 k 个元素（下标差 ≤ k）
// 用哈希集合存窗口内的值：新元素若已在集合中，说明 k 范围内有重复 → true
// 出窗时机：窗口超过 k 个时，滑出下标 right-k 的元素（也可用纯哈希记录每个值的最新下标）

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> window;                 // 窗口内的值（至多 k 个）
        for (int right = 0; right < (int)nums.size(); right++) {
            if (window.count(nums[right])) return true;  // 1. 入：命中即存在近重复
            window.insert(nums[right]);
            if ((int)window.size() > k)                  // 2/3. 出：窗口超过 k 个
                window.erase(nums[right - k]);
        }
        return false;
    }
};