- [排序算法](#排序算法)
  - [1.快速排序](#1快速排序)
  - [2.插入排序](#2插入排序)

# [排序算法](https://leetcode-cn.com/problems/sort-an-array/)

## 1.快速排序

```
class Solution {
public:
    // 5, 3, 2, 6, 4, 7
    int partition(vector<int>& nums, int i, int j) {
        int pivot = nums[i];
        while(i < j) {
            while(i < j && nums[j] >= pivot) {
                j--;
            }
            nums[i] = nums[j];
            while(i < j && nums[i] <= pivot) {
                i++;
            }
            nums[j] = nums[i];
            }
        nums[i] = pivot;
        return i;
    }
    // 注意随机选择，否则过不了
    int randomized_partition(vector<int>& nums, int l, int r) {
        int i = rand() % (r - l + 1) + l; // 随机选一个作为我们的主元
        swap(nums[r], nums[i]);
        return partition(nums, l, r);
    }

    void quick_sort(vector<int>& nums, int i, int j) {
        if(i < j) {
            int k = randomized_partition(nums, i, j);
            quick_sort(nums, i, k-1);
            quick_sort(nums, k+1, j);
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        quick_sort(nums, 0, nums.size()-1);
        return nums;
    }
};
```

## 2.插入排序
此题使用插入排序会超时

```
class Solution {
public:
    void insert_sort(vector<int>& nums) {
        if(nums.empty()) {
            return;
        }
        int size = nums.size(), i = 0, j = 0;
        for(i=1; i < size; i++) {
            int tmp = nums[i];
            for(j = i-1; j >= 0 && nums[j] > tmp; j--) {
                nums[j+1] = nums[j];
            }
            nums[j+1] = tmp;
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        insert_sort(nums);
        return nums;
    }
};
```