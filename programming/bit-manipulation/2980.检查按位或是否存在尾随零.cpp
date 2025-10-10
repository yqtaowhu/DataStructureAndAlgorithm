/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2980.检查按位或是否存在尾随零.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taoyanqi <taoyanqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 09:20:22 by taoyanqi          #+#    #+#             */
/*   Updated: 2025/10/10 09:20:23 by taoyanqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

class Solution {
public:
    bool hasTrailingZeros(vector<int>& nums) {
        int res = 0;
        for(auto num : nums) {
            // 检查最后一位是不是0
            if((num & 1) == 0) {
                res++;
            }
            //cout << num << res << endl;;
        }
        return res > 1;
        
    }
};