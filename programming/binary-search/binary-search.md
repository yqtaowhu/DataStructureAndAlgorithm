# 二分算法相关题目


二分寻找左右边界的做法，一定要会的左闭右开

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
```