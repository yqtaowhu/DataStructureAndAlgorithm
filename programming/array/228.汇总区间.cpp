/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   228.汇总区间.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taoyanqi <taoyanqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 19:38:06 by taoyanqi          #+#    #+#             */
/*   Updated: 2024/04/04 19:38:07 by taoyanqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


vector<string> summaryRanges(vector<int>& nums) {
    vector<string> res;
    int m = nums.size();
    if (m == 0) return res;
    int beg = 0;
    string tmp;
    // 需要特殊处理最右的逻辑
    for(int i= 1; i<=m; i++) {
        if(i == m || nums[i] != nums[i-1] + 1) {
            if(beg == i - 1) {
                tmp = to_string(nums[beg]);
            } else {
                tmp = to_string(nums[beg]) + "->" + to_string(nums[i-1]);
            }
            res.push_back(tmp);
            beg = i;
        }
    }
    return res;
}