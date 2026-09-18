/*
 * @lc app=leetcode.cn id=215 lang=cpp
 *
 * [215] 数组中的第K个最大元素
 */

// @lc code=start
/*
堆的方法
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // 应该使用小根堆，那么堆顶就是最小的值
        priority_queue<int,vector<int>,greater<int>> q;
        for(auto it:nums){
            q.push(it);
            if(q.size()>k) q.pop();
        }
        return q.top();
    }
};

*/
class Solution {
public:
    // 快排思路
    int partition(vector<int>& data, int left, int right) {
        int i = left, j = right, pivot = data[left];
        while (i < j) {
            while (i < j&&data[j] >= pivot) j--;
            data[i] = data[j];
            while (i < j&&data[i] <= pivot) i++;
            data[j] = data[i];
        }
        data[i] = pivot;
        return i;
    }

    int findKthLargest(vector<int>& nums, int k) {
        if(nums.empty()) return 0;
        int length = nums.size();
        int left = 0, right = length - 1;
        int index = partition(nums, 0, right);
        while(index != length - k) {
            if(index > length - k) {
                right = index - 1;
                index = partition(nums, left, right);
            } else {
                left = index + 1;
                index = partition(nums, left, right);
            }
        }
        return nums[index];       
    }
};
// @lc code=end

