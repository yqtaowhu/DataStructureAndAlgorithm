/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   节点间通路.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taoyanqi <taoyanqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 21:00:38 by taoyanqi          #+#    #+#             */
/*   Updated: 2024/05/08 21:00:52 by taoyanqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// https://leetcode.cn/problems/route-between-nodes-lcci/solutions/1146072/mian-shi-ti-0401-jie-dian-jian-tong-lu-c-6j3q/?envType=study-plan-v2&envId=cracking-the-coding-interview
class Solution {
public:
    bool findWhetherExistsPath(int n, vector<vector<int>>& graph, int start, int target) {
        if(start == target) return true;
        // [[0, 1], [0, 2], [1, 2], [1, 2]]
        // 0 -> 1, 2
        // 1 -> 2
        // 构建邻接表
        unordered_map<int, vector<int>> map;
        for(auto v : graph) {
            map[v[0]].push_back(v[1]);
        }
        // bfs流程
        queue<int> que;
        que.push(start);
        // 注意有环情况
        vector<int> vis(n, 0);
        while(!que.empty()) {
            int x = que.front();
            if(x == target) {
                return true;
            }
            que.pop();
            vis[x] = 1;
            if(map.find(x) != map.end()) {
                for(auto x : map[x]) {
                    if(vis[x] == 0) {
                        que.push(x);
                    }
                }
            }
        }
        return false;

    }
};