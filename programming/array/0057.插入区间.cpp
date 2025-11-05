/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0057.插入区间.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taoyanqi <taoyanqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 12:56:13 by taoyanqi          #+#    #+#             */
/*   Updated: 2025/11/05 12:56:45 by taoyanqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        int i = 0, n = intervals.size();
        // 在newInterval的左边，不重合
        while (i < n && intervals[i][1] < newInterval[0]) {
            ans.push_back(intervals[i++]);
        }
        // intervals[i][1] >= newInterval[0] && intervals[i][0] <= newInterval[1] 有重合
        while (i < n && intervals[i][0] <= newInterval[1]) {
            newInterval[0] = min(intervals[i][0], newInterval[0]);
            newInterval[1] = max(intervals[i][1], newInterval[1]);
            ++i;
        }
        ans.push_back(newInterval);
        // 在newInterval的右边，不重合
        while (i < n) ans.push_back(intervals[i++]);
        return ans;
    }
};