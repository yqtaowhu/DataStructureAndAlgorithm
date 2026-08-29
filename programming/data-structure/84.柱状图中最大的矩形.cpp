/*
 * @lc app=leetcode.cn id=84 lang=cpp
 *
 * [84] 柱状图中最大的矩形
 */

// @lc code=start
/*
// 暴力做法，枚举任意两个边组成的矩形，宽为索引间隔，高为索引区间内的最小值
int largestRectangleArea(vector<int>& heights) {
    int m = heights.size(), res = 0;
    for(int i=0; i<m; i++) {
        int height = INT_MAX;
        for(int j=i; j<m; j++) {
            height = min(height, heights[j]);
            res = max(res, (j-i+1) * height);
        }
    }
    return res;
}
*/
#include<iostream>
#include<vector>
#include <stack>
using namespace std;

class Solution {
public:
    // [6, 7, 5, 2, 4, 5, 9, 3]
    int largestRectangleArea(vector<int>& heights) {
        int m = heights.size(), res = 0;
        stack<int> st;
        st.push(-1);
        for(int i=0; i<m; i++) {
            // 栈不空，且当前元素小于等于栈顶
            while(st.top()!= -1 && heights[st.top()] >= heights[i]) {
                int index = st.top();
                st.pop();
                res = max(res, heights[index] * (i-st.top()-1)); 
            }
            st.push(i);
        }
        // 弹出所有的元素，此时的栈是一个单调递增的栈index : [-1,3,7]
        while(st.top() != -1) {
            int index = st.top();
            st.pop();
            // 3*(7-3) ,  2*(7-(-1))
            res = max(res, heights[index] * (m - st.top() -1));
        }
        return res;
    }
};
// @lc code=end

