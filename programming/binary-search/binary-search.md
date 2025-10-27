# 二分模版

1. 使用闭区间[left, right]
2. left < right: 求边界位置，最小值
3. left <= right: 求具体值

34. 寻找边界
左闭右开的写法, 一定要会的

```
    int lower_bound(vector<int> &nums, int target) {
        // lower_bound 返回最小的满足 nums[i] >= target 的下标 i
        int left=0, right = nums.size();
        // 左闭右开
        while(left < right) {
            int mid = left + (right - left) / 2;
            if(nums[mid] >= target) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        // 循环结束后 left = right
        // 此时 nums[left-1] < target 而 nums[left] = nums[right] >= target
        // 所以 left 就是第一个 >= target 的元素下标
        return left;
    }

    int upper_bound(vector<int> &nums, int target) {
        int left=0, right = nums.size();
        // 左闭右开
        while(left < right) {
            int mid = left + (right - left ) / 2;
            if(nums[mid] > target) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
```



135. 寻找旋转排序数组中的最小值
```
class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size()-1;
        while(left < right) {
            int mid = left + (right-left) / 2;
            // 最小值可能是[left, mid]
            if(nums[mid] <= nums[right]) {
                right = mid;
            } else {
                left = mid+1;
            }
        }
        return nums[left];
    }
};
```
