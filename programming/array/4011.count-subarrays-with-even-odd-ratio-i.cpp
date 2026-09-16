/*
 * @lc app=leetcode.cn id=4011 lang=cpp
 * @lcpr version=30204
 *
 * [4011] 按奇偶比统计子数组 I
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
    int countRatioSubarrays(vector<int>& nums, int a, int b) {
        int n = nums.size();
        int ans = 0;
        // 枚举子数组左端点 i
        for (int i = 0; i < n; i++) {
            int x = 0, y = 0; // x: 偶数个数, y: 奇数个数
            // 右端点 j 从 i 向右扩展，边扩展边维护区间内的奇偶数量
            for (int j = i; j < n; j++) {
                if (nums[j] & 1) y++;
                else x++;
                // 有效条件：y > 0 且 x / y <= a / b
                // 交叉相乘改写为 x * b <= a * y，避免浮点数精度误差
                if (y > 0 && 1LL * x * b <= 1LL * a * y) ans++;
            }
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,1,2]\n3\n2\n
// @lcpr case=end

// @lcpr case=start
// [2,2,1]\n2\n1\n
// @lcpr case=end

// @lcpr case=start
// [2,2,2]\n1\n1\n
// @lcpr case=end

 */

