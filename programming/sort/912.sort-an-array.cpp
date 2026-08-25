/*
 * @lc app=leetcode.cn id=912 lang=cpp
 * @lcpr version=30204
 *
 * [912] 排序数组
 */


// @lcpr-template-start
using namespace std;
#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    int partition(vector<int>& nums, int left, int right) {
        int randomIdx = left + rand() % (right - left + 1);
        swap(nums[left], nums[randomIdx]);
        int pivot = nums[left];
        int i = left, j = right;
        while (i < j) {
            // 从右找一个比pivot小的
            while(i < j && nums[j] >= pivot) {
                j--;
            }
            //从左找一个比pivot大的
            nums[i] = nums[j];
            while(i < j && nums[i] <= pivot) {
                i++;
            }
            nums[j] = nums[i];
        }
        nums[i] = pivot; // 回填 pivot
        return i;         // 返回 pivot 最终位置
    }
    void quickSort(vector<int>& nums, int left, int right) {
        if (left >= right) return;
        int k = partition(nums, left, right);
        quickSort(nums, left, k - 1);
        quickSort(nums, k + 1, right);
    }
    vector<int> sortArray(vector<int>& nums) {
        quickSort(nums, 0, nums.size() - 1);
        return nums;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [5,2,3,1]\n
// @lcpr case=end

// @lcpr case=start
// [5,1,1,2,0,0]\n
// @lcpr case=end

 */

