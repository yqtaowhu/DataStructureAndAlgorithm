/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1524.和为奇数的子数组数目.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taoyanqi <taoyanqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 12:40:05 by taoyanqi          #+#    #+#             */
/*   Updated: 2025/09/22 12:40:05 by taoyanqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        const int MODULO = 1000000007;
        int odd = 0, even = 1;
        int subarrays = 0;
        int sum = 0;
        int length = arr.size();
        for (int i = 0; i < length; i++) {
            sum += arr[i];
            subarrays = (subarrays + (sum % 2 == 0 ? odd : even)) % MODULO;
            if (sum % 2 == 0) {
                even++;
            } else {
                odd++;
            }
        }
        return subarrays;
    }

    // ===== 模板版：前缀和 + 哈希表（见 前缀和哈希表模板.md · 模式一）=====
    // 前缀和只保留奇偶(mod 2)：子数组和为奇 <=> 两端前缀奇偶不同。
    // 于是对当前奇偶 s，累加历史中奇偶为 s^1 的前缀个数——就是计数型模板。
    // 上面的 odd/even 双变量，其实是这个哈希表在「只有 0/1 两种余数」下的特化。
    int numOfSubarraysByPrefix(vector<int>& arr) {
        const int MOD = 1000000007;
        unordered_map<int, int> cnt{{0, 1}}; // 前缀和奇偶(0/1) -> 出现次数
        int ans = 0, s = 0;
        for (int x : arr) {
            s = (s + x) & 1;                 // 只保留奇偶
            ans = (ans + cnt[s ^ 1]) % MOD;  // 和为奇数 <=> 两端奇偶不同
            cnt[s]++;
        }
        return ans;
    }
};