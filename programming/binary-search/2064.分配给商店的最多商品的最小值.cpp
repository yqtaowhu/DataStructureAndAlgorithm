/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2064.分配给商店的最多商品的最小值.cpp                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taoyanqi <taoyanqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/31 by taoyanqi                        #+#    #+#             */
/*   Updated: 2026/08/31 by taoyanqi                        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// 2064. 分配给商店的最多商品的最小值
// 「最小化最大值」经典题：二分每店上限 x，check(x) = sum(ceil(q/x)) <= n
// 每个商店只能放一种商品，数量 q 需要 ceil(q/x) 个商店
class Solution {
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        auto check = [&](int x) {           // 上限 x 时需要的商店数
            long long need = 0;
            for (int q : quantities) need += (q - 1) / x + 1;
            return need <= n;
        };
        int left = 1, right = *max_element(quantities.begin(), quantities.end());
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (check(mid)) right = mid;
            else left = mid + 1;
        }
        return left;
    }
};
