/*
 * @lc app=leetcode.cn id=85 lang=cpp
 *
 * [85] 最大矩形
 */

// @lc code=start
class Solution {
public:
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

    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.size()<=0 || matrix[0].size()<=0) return 0;
        int row = matrix.size(), col = matrix[0].size();
        vector< vector<int> > heights(row, vector<int>(col));

        int maxArea = 0;
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++) {
                if (matrix[i][j]=='1'){
                    heights[i][j] = (i==0 ? 1 : heights[i-1][j] + 1);
                }
            }
            int area = largestRectangleArea(heights[i]);
            if (area > maxArea) maxArea = area;
        }
        return maxArea;
    }
};
// @lc code=end

