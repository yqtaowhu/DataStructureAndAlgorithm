// https://leetcode.cn/problems/container-with-most-water/

// 简单的双指针
class Solution {
public:
    int maxArea(vector<int>& height) {
        int size = height.size();
        if(size <= 1) return 0;
        int res = 0, left = 0, right=size-1;
        while(left < right) {
            if(height[left] <= height[right]) {
                res = max(res, (right-left) * height[left]);
                left++;
            } else {
                res = max(res, (right-left) * height[right]);
                right--;
            }
        }
        return res;
    }
};