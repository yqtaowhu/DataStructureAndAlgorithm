/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   26.删除重复元素.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taoyanqi <taoyanqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 20:54:15 by taoyanqi          #+#    #+#             */
/*   Updated: 2024/04/22 20:54:23 by taoyanqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int removeDuplicates(vector<int>& nums) {
    int m = nums.size();
    if(m <= 1) return m;
    int end = 0;
    for(int i=1; i < m; i++) {
        if(nums[i] != nums[end]) {
            //cout << end << " " << i << endl;
            end++;
            nums[end] = nums[i];
        }
    }
    //cout << nums[0] << nums[1] << endl;
    return end + 1;
}