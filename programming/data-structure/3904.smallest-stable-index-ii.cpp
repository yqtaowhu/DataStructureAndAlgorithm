/*
 * @lc app=leetcode.cn id=3904 lang=cpp
 * @lcpr version=30204
 *
 * [3904] 最小稳定下标 II
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
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> suf_min(n); // 后缀最小值
        suf_min[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            suf_min[i] = min(suf_min[i + 1], nums[i]);
        }

        int pre_max = 0; // 前缀最大值
        for (int i = 0; i < n; i++) {
            pre_max = max(pre_max, nums[i]);
            if (pre_max - suf_min[i] <= k) {
                return i;
            }
        }
        return -1;
    }
};

// @lc code=end



/*
// @lcpr case=start
// [5,0,1,4]\n3\n
// @lcpr case=end

// @lcpr case=start
// [3,2,1]\n1\n
// @lcpr case=end

// @lcpr case=start
// [0]\n0\n
// @lcpr case=end

 */

