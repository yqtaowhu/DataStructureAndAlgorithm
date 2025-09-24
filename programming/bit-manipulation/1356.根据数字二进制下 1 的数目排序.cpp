/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1356.根据数字二进制下 1 的数目排序.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taoyanqi <taoyanqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 11:11:26 by taoyanqi          #+#    #+#             */
/*   Updated: 2025/09/24 11:11:26 by taoyanqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        vector<int> bit(10001, 0);
        for (int i = 1; i <= 10000; ++i) {
            bit[i] = bit[i >> 1] + (i & 1);
        }
        sort(arr.begin(), arr.end(), [&](int x, int y){
            if (bit[x] == bit[y]) {
                return x < y;
            }
            return bit[x] < bit[y];
        });
        return arr;
    }
};