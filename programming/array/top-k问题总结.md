- [top k 问题总结](#top-k-%e9%97%ae%e9%a2%98%e6%80%bb%e7%bb%93)
  - [1.最小的k个数](#1%e6%9c%80%e5%b0%8f%e7%9a%84k%e4%b8%aa%e6%95%b0)
  - [2.两个排序数组第k小的数](#2%e4%b8%a4%e4%b8%aa%e6%8e%92%e5%ba%8f%e6%95%b0%e7%bb%84%e7%ac%ack%e5%b0%8f%e7%9a%84%e6%95%b0)

# top k 问题总结

## [1.最小的k个数](https://leetcode-cn.com/problems/zui-xiao-de-kge-shu-lcof/)

输入整数数组 arr ，找出其中最小的 k 个数。例如，输入4、5、1、6、2、7、3、8这8个数字，则最小的4个数字是1、2、3、4。

**方法1: 堆**

使用优先队列存储k个元素，当新的元素来临时，与根进行比较，符合条件，将根pop, push新的元素。
```
class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        if(arr.size() <= k ) return arr;
        vector<int> res;
        if(k==0) return res;
        priority_queue<int, vector<int>, less<int> > que;
        for(int i=0; i<k; i++) {
            que.push(arr[i]);
        }
        for(int i=k; i<arr.size(); i++) {
            if(arr[i] < que.top()) {
                que.pop();
                que.push(arr[i]);
            }
        }   
        //vector<int> res(que.begin(), que.end())
        for(int i=0; i<k; i++) {
            res.push_back(que.top());
            que.pop();
        }
        return res;
    }
};
```

**方法2: 快排方法**

快排中的partition操作，会使得  pivot 左右两边有序

```
class Solution {
public:
    int partition(vector<int>& input,int beg,int end) {
		int pivot = input[beg];
        int i=beg,j=end;
        while(i<j){
            while(i<=j&&input[j]>=pivot) 
                j--;
            input[i] = input[j];
            while(i<=j&&input[i]<=pivot)
                i++;
            input[j] = input[i];
        }
        input[i] = pivot;
        return i;
    }
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
		int size = input.size();
        if (size <= 0 || k <= 0 || k > size) return vector<int>();
        int left = 0,right=size-1;
        int p = partition(input,left,right);
        while(p!=k-1) {
            if(p<k-1) {
                left = p+1;
                p = partition(input,left,right);
            }
            else {
                right = p-1;
                p = partition(input,left,right);
        	}
        }
        vector<int>ret(input.begin(),input.begin()+k);
        return ret;
	}
};
```

## [2.两个排序数组第k小的数](https://leetcode-cn.com/problems/median-of-two-sorted-arrays/)

此题可以看做考虑两个有序数组的第k小的数。https://www.acwing.com/solution/LeetCode/content/50/

```
int findKthNumber(vector<int> &nums1, int i, vector<int> &nums2, int j, int k) {
    // 使得nums1为短数组
    if (nums1.size() - i > nums2.size() - j) return findKthNumber(nums2, j, nums1, i, k);
    // nums1剩余数组长度为空，则直接返回nums2当前数组长度的第k个数字
    if (nums1.size() == i) return nums2[j + k - 1];
    // k == 1特殊情况
    if (k == 1) return min(nums1[i], nums2[j]);
    // 考虑nums1应该取的元素个数，如果 nums1有足够的元素，则取 k/2 
    // 如果没有足够的元素了，则取最后一个元素进行比较
    int si = min(i + k / 2, int(nums1.size())), sj = j + k / 2;
    if (nums1[si - 1] > nums2[sj - 1]) {
        // 这时取nums2 k/2
        return findKthNumber(nums1, i, nums2, j + k / 2, k - k / 2);
    }
    else {
        // 取nums1 k/2 si-i
        return findKthNumber(nums1, si, nums2, j, k - (si - i));
    }
}
```