/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   452用最少数量的箭引爆气球.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taoyanqi <taoyanqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 20:30:14 by taoyanqi          #+#    #+#             */
/*   Updated: 2024/06/05 20:30:36 by taoyanqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if(points.empty()) return 0;
        sort(points.begin(), points.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];
        });
        //sort(points.begin(), points.end());
        // 1 6,  2 8,  7 12, 10 16
        vector<vector<int> > res;
        res.push_back(points[0]);
        for(int i=1; i < points.size(); i++) {
            vector<int> tmp = res.back();
            // 有交集
            if(points[i][0] <= tmp[1]) {
                int left = max(points[i][0], tmp[0]);
                int right = min(points[i][1], tmp[1]);
                res.back() = vector<int> {left, right};
            } else {
                res.push_back(points[i]);
            }
        }
        return res.size();
    }
};