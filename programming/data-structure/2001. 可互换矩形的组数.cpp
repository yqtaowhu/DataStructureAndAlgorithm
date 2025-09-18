/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2001. 可互换矩形的组数.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taoyanqi <taoyanqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 09:22:03 by taoyanqi          #+#    #+#             */
/*   Updated: 2025/09/18 09:22:05 by taoyanqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

class Solution {
public:
    // 可以直接使用double做key
    // 通用可以计算出最大公约数，然后都除以最大公约数做key
    int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }
    long long interchangeableRectangles(vector<vector<int>>& rectangles) {
        unordered_map<double, int> mp;
        long long ans = 0;
        for(auto &x : rectangles) {
            ans += mp[x[0] * 1.0 / x[1]];
            mp[x[0] * 1.0 / x[1]]++;
        }
        return ans;
        
    }
};