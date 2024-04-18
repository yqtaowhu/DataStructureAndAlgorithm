/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   69.x-的平方根.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taoyanqi <taoyanqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 20:26:24 by taoyanqi          #+#    #+#             */
/*   Updated: 2024/04/18 20:27:02 by taoyanqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * @lc app=leetcode.cn id=69 lang=cpp
 *
 * [69] x 的平方根
 */

// @lc code=start
class Solution {
public:
    int mySqrt(int x) {
        if (0 == x) return 0;
        int left = 1, right = x, ans;
        while (left <= right) {
            // 注意mid写法，这样不会超出限制
            int mid = left + (right - left) / 2;
            if (mid <= x / mid) {
                left = mid + 1;
                ans = mid;
            } else {
                right = mid - 1;
            }
        }
        return ans;
    }
};
// 通用的二分法

int binary_search(int x) {
    double l=1, r = x;
    while(r-l > 1e-6) {
        double mid = (l+r)/2;
        if (mid * mid >= x) r = mid;
        else l = mid;
    }
    return int(r);
}
// http://en.wikipedia.org/wiki/Newton%27s_method
int sqrt_nt(int x) {
    if (x == 0) return 0;
    double last = 0;
    double res = 1;
    while (res != last)
    {
        last = res;
        res = (res + x / res) / 2;
    }
    return int(res);
}

// @lc code=end

