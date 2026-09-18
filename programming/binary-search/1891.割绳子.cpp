/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1891.割绳子.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taoyanqi <taoyanqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/31 by taoyanqi                        #+#    #+#             */
/*   Updated: 2026/08/31 by taoyanqi                        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// 1891. 割绳子（会员题）
// 同 410 思路的「最大化最小值」：二分绳段长度 len，check(len) = sum(r/len) >= k
// len 越大越难满足，套模板的最大值技巧：找第一个 check 为 false 的位置再减一
class Solution {
public:
    int maxLength(vector<int>& ribbons, int k) {
        if (accumulate(ribbons.begin(), ribbons.end(), 0LL) < k) return 0;
        auto check = [&](long long len) {   // 长度 len 能切出几段
            long long cnt = 0;
            for (int r : ribbons) cnt += r / len;
            return cnt >= k;
        };
        long long left = 1;
        long long right = *max_element(ribbons.begin(), ribbons.end()) + 1LL;
        while (left < right) {
            long long mid = left + (right - left) / 2;
            if (check(mid)) left = mid + 1;   // mid 可行，答案可能更大
            else right = mid;                 // mid 不可行，可能是分界
        }
        return left - 1;
    }
};
