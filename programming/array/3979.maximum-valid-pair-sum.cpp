/*
 * @lc app=leetcode.cn id=3979 lang=cpp
 * @lcpr version=30204
 *
 * [3979] 最大有效数对和
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
    int maxValidPairSum(vector<int>& nums, int k) {
        // 1,3,5,2,8
        //     j     固定j， 找nums[i]的最大值， j每增加1， j-k的最大值也只是更新1个值，所以可以直接维护
        int ans = 0, mx = 0;
        for (int j = k; j < nums.size(); j++) {
            mx = max(mx, nums[j - k]); // nums[i] 的最大值
            ans = max(ans, mx + nums[j]);
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,3,5,2,8]\n2\n
// @lcpr case=end

// @lcpr case=start
// [5,1,9]\n1\n
// @lcpr case=end

 */

