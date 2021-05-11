- [排序算法](#排序算法)
  - [1.快速排序](#1快速排序)
  - [2.插入排序](#2插入排序)
  - [3.冒泡排序](#3冒泡排序)
  - [4.归并排序](#4归并排序)

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

## 3.冒泡排序

```
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        // 冒泡排序
        if(nums.empty()) {
            return nums;
        }
        int size = nums.size(), exchange = 1;
        // 5 2 3 1
        for(int i=0; i < size-1; i++) {
            exchange = 0;
            for(int j=size-1; j > i; j--) {
                if(nums[j-1] > nums[j]) {
                    exchange = 1;
                    swap(nums[j-1], nums[j]);
                }
            }
            if(exchange == 0) {
                break;
            }
        }
        return nums;

    }
};
```

## 4.归并排序

```
class Solution {
public:
    void merge(vector<int>& nums, int l, int mid, int r) {
        // 1 2 5   3 4 6
        int i = l, j = mid + 1, k = 0;
        vector<int> v(r - l + 1);
        while(i <= mid && j <= r) {
            if(nums[i] <= nums[j]) {
                v[k++] = nums[i++];
            } else {
                v[k++] = nums[j++];
            }
        }
        while(i <= mid) {
            v[k++] = nums[i++];
        }
        while(j <= r) {
            v[k++] = nums[j++];
        }
        for(int i=0; i < k; i++) {
            nums[l+i] = v[i];
        }
    }
    void merge_sort(vector<int>& nums, int i, int j) {
        // 5, 2 , 1, 3, 6, 4
        if(i < j) {
            int mid = (i + j) / 2;
            merge_sort(nums, i, mid);
            merge_sort(nums, mid+1, j);
            merge(nums, i, mid , j);
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        merge_sort(nums, 0, nums.size()-1);
        return nums;
    }
};
```