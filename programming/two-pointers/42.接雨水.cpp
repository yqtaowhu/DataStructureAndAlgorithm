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
#include<vector>
using namespace std;


class Solution {
public:
    int trap(vector<int>& height) {
        // 找到当前位置的左边最高和右边最高的高度
        int n = height.size();
        vector<int> left(n,0), right(n,0);
        int max_left=0, max_right=0;
        // 当前位置左边最大高度
        for(int i=1; i<n;i++) {
            left[i] = max(left[i-1], height[i-1]);
        }
        // 当前位置右边最大高度
        for(int i=n-2; i>=0;i--) {
            right[i] = max(right[i+1], height[i+1]);
        }

        int res = 0;
        // 遍历每个位置，求每个位置的存储量
        for(int i=1; i<n-1; i++) {
            int min_edge = min(left[i], right[i]);
            // 满足条件
            if(min_edge > height[i]) {
                res += min_edge - height[i];
            }
        }
        return res; 
    }
};
// @lc code=end

