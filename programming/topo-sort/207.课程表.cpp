/*
 * @lc app=leetcode.cn id=207 lang=cpp
 *
 * [207] 课程表
 */

// @lc code=start
#include <iostream>
#include <vector>

using namespace std;

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
};

// @lc code=end
