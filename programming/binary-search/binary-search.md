# 二分算法相关题目

```
// 查找左边界
int l = 0, r = n - 1;
while (l < r) {
    int mid = l + r >> 1;
    if (q[mid] >= x) r = mid;
    else l = mid + 1;
}

// 查找右边界
int l = 0, r = n - 1;
while (l < r) {
    int mid = l + r + 1 >> 1;
    if (q[mid] <= x) l = mid;
    else r = mid - 1;
}
```

## [1.搜索旋转排序数组](https://leetcode-cn.com/problems/search-in-rotated-sorted-array/)

```
// 分两部分，第一部分，找到最小值，然后正常二分
class Solution {
public:
    // 特别注意这个二分的写法
    int search_lowers_index(vector<int> &nums) {
        int left = 0, right = nums.size() -1;
        while(left < right) {
            int mid = (left + right) / 2;
            if(nums[mid] > nums[right])
                left = mid + 1;
            else right = mid;
        }
        return left;
    }

    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() -1 ;
        int low_index = search_lowers_index(nums);
        while(left <= right) {
            int mid = (left + right) / 2;
            int real_mid = (mid + low_index) % nums.size();
            //cout << real_mid << endl;
            if(nums[real_mid] == target) {
                return real_mid;
            } else if(nums[real_mid] > target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return -1;
    }
};
```
// 另外一种解放
```
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = (int)nums.size();
        if (!n) {
            return -1;
        }
        if (n == 1) {
            return nums[0] == target ? 0 : -1;
        }
        int l = 0, r = n - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (nums[mid] == target) return mid;
            if (nums[0] <= nums[mid]) {
                if (nums[0] <= target && target < nums[mid]) {
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            } else {
                if (nums[mid] < target && target <= nums[n - 1]) {
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
        }
        return -1;
    }
};
```

