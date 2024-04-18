/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   66.加一.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taoyanqi <taoyanqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 21:19:45 by taoyanqi          #+#    #+#             */
/*   Updated: 2024/04/18 21:19:53 by taoyanqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

class Solution {
public:
    // 1 2 3; 9
    vector<int> plusOne(vector<int>& digits) {
        int i = digits.size() - 1;
        ++digits[i]; // 末位加1
        while (digits[i] == 10) { // 遇10进位
            if (i == 0) {
                digits[i] = 1; // 首位变成1
                digits.push_back(0); // 末尾补个0
                break;
            } else {
                digits[i] = 0;
                --i;
                ++digits[i];
            }
        }
        return digits;
    }
};