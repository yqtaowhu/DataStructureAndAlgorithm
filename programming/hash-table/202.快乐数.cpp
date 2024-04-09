/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   202.快乐数.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taoyanqi <taoyanqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 20:56:05 by taoyanqi          #+#    #+#             */
/*   Updated: 2024/04/09 20:56:06 by taoyanqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// 模拟即可，唯一需要注意的是就是使用哈希表检测环
class Solution {
public:
    int get_next(int x) {
        int res = 0;
        while(x) {
            int t = x % 10;
            res += t * t;
            x = x / 10;
        }
        return res;
    }
    // 1. 结果1； 2. 有环，3，考虑不会无穷大
    bool isHappy(int n) {
        unordered_set<int> hash;
        while(n != 1 && !hash.count(n)) {
            hash.insert(n);
            n = get_next(n);
        } 
        return n == 1;
    }
};