/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0055.跳跃游戏.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taoyanqi <taoyanqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 18:13:13 by taoyanqi          #+#    #+#             */
/*   Updated: 2025/10/29 18:13:22 by taoyanqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size(), max_far = 0;
        for(int i=0; i < n; i++) {
            if(max_far < i) {
                return false;
            }
            max_far = max(max_far, i + nums[i]);
            // 提前结束
            if(max_far >= n-1) {
                return true;
            }
        }
        return true;   
    }
};