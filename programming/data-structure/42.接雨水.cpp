/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 */

// @lc code=start

/*
可以优化成两个变量去求解，max_left,max_right
    if (height[left - 1] < height[right + 1]) {
        max_left = Math.max(max_left, height[left - 1]);
        int min = max_left;
        if (min > height[left]) {
            sum = sum + (min - height[left]);
        }
        left++;
    //从右到左更
    } else {
        max_right = Math.max(max_right, height[right + 1]);
        int min = max_right;
        if (min > height[right]) {
            sum = sum + (min - height[right]);
        }
        right--;
    }
参考资料：https://leetcode-cn.com/problems/trapping-rain-water/solution/xiang-xi-tong-su-de-si-lu-fen-xi-duo-jie-fa-by-w-8/
*/


// 单调栈的做法一定要回，比较清晰明了
class Solution {
public:
    int trap(vector<int>& height) {
        // 0,1,0,2,1,0,1,3,2,1,2,1
        // 维护单调递减栈, 当前元素比栈顶大，则更新计算
        if(height.empty()) return 0;
        stack<int> st;
        int res = 0;
        for (int i = 0; i < height.size(); i++) {
            while (!st.empty() && height[i] >= height[st.top()]) {
                int bottom_h = height[st.top()];
                st.pop();
                // 在小元素出栈后，要考虑其左边的元素，根据这个统计
                if (st.empty()) {
                    break;
                }
                int left = st.top();
                int dh = min(height[left], height[i]) - bottom_h; // 面积的高
                res += dh * (i - left - 1);
            }
            st.push(i);
        }
        return res;
    }
};
// @lc code=end

