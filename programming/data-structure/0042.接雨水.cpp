/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0042.接雨水.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taoyanqi <taoyanqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 09:29:44 by taoyanqi          #+#    #+#             */
/*   Updated: 2025/10/29 09:32:39 by taoyanqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// 动态规划
class Solution {
public:
    // 动态规划，需要知道当前位置左边的最大值和右边最大值min(left, right) - height
    // 可以考虑加上当前位置，如果最大值在当前位置，那么就是0
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> leftmax(n,0), rightmax(n, 0);
        leftmax[0] = height[0];
        for(int i=1; i < n; i++) {
            leftmax[i] = max(leftmax[i-1], height[i]);
        }
        rightmax[n-1] = height[n-1];
        for(int i=n-2; i>=0; i--) {
            rightmax[i] = max(rightmax[i+1], height[i]);
        }
        int res = 0;
        for(int i=0; i<n; i++) {
            res += min(leftmax[i], rightmax[i]) - height[i];
        }
        return res;

        
    }
};


// 双指针

class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0;
        int left = 0, right = height.size() - 1;
        int leftMax = 0, rightMax = 0;
        while (left < right) {
            leftMax = max(leftMax, height[left]);
            rightMax = max(rightMax, height[right]);
            if (height[left] < height[right]) {
                ans += leftMax - height[left];
                ++left;
            } else {
                ans += rightMax - height[right];
                --right;
            }
        }
        return ans;
    }
};


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

