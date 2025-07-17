/*
 * @lc app=leetcode.cn id=210 lang=cpp
 *
 * [210] 课程表 II
 */

// @lc code=start

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 只加入入度为0的点
// 每次讲nxt的入度都减1
// 最后判断是不是所有入度都为0
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int> > graph(numCourses); // 构造邻接表
        vector<int> indegree(numCourses, 0), res; // 顶点入度
        for(auto &pre : prerequisites) {
            //cout << pre[0] << " " << pre[1] << " " << endl;
            graph[pre[1]].push_back(pre[0]);
            indegree[pre[0]] += 1;
        }
        // 广搜解拓扑排序问题，入队所有入度为0的点
        queue<int> que;
        for(int i=0; i < numCourses; i++) {
            if(indegree[i] == 0) {
                que.push(i);
                //res.push_back(i);   // 加入
            }
        }
        while(!que.empty()) {
            int cur = que.front();
            que.pop();
            res.push_back(cur);
            //cout << cur << endl;
            // 遍历相邻节点, 所有指向结点入度-1
            for(auto &nxt : graph[cur]) {
                indegree[nxt]--;
                // 入度为0加入队列
                if(indegree[nxt] == 0) {
                    que.push(nxt); 
                }
            }
        }
        for (int i = 0; i < indegree.size(); ++i) {
            if (indegree[i] != 0) {
                return vector<int>();
            }
        }
        return res;  

    }
};

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> flag(numCourses,0);//标志
        vector<vector<int> > adjacency(numCourses);
        if(prerequisites.empty()) return true; 
        // 构建邻接表
        for(int i=0;i<prerequisites.size();i++) {
            adjacency[prerequisites[i][1]].push_back(prerequisites[i][0]);//对于该课程来说需要修的课
        }
        for(int i=0;i<numCourses;i++) {
            // 对每一个节点进行遍历，当前节点有环，直接return
            if(!dfs(i, flag, adjacency))
                return false;
        }
        return true;
    }
    bool dfs(int i,vector<int> &flag,vector<vector<int> > &adjacency) {
        if(flag[i]==1) {
            return false;
        }
        if(flag[i]==-1) {
            return true; //可以确定从该结点出发没有回路   
        }
        flag[i] = 1;
        for(int j=0;j<adjacency[i].size();j++) {
            if(!dfs(adjacency[i][j],flag,adjacency)) 
                return false;
        }
        flag[i] = -1;//该结点出去的每一个结点都访问完了，没有回路
        return true;
    }

    void dfs_2(int i, vector<int>& marked, vector<int>& res, vector<vector<int>>& adjacency) {
        marked[i] = 1;
        for(int j=0; j<adjacency[i].size(); j++) {
            int w = adjacency[i][j];
            if(marked[w] == 0)
                dfs_2(w, marked, res, adjacency);
        }
        res.push_back(i); //后续
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
       // 首先检查是否有环 
        vector<int> res;
        vector<int> marked(numCourses,0);
        if(!canFinish(numCourses, prerequisites)) {
            return res;
        }
        vector<vector<int> > adjacency(numCourses);
        for(int i=0;i<prerequisites.size();i++) {
            adjacency[prerequisites[i][1]].push_back(prerequisites[i][0]);//对于该课程来说需要修的课
        }

        for(int i=0; i<numCourses; i++) {
            if(marked[i] == 0) {
                dfs_2(i, marked, res, adjacency);
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
// @lc code=end

