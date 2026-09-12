/*
 * @lc app=leetcode.cn id=69 lang=cpp
 * @lcpr version=30204
 *
 * [69] x 的平方根 
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
// ... existing code ...
// @lc code=start
class Solution {
public:
    // 二分找第一个平方 > x 的位置（红蓝染色，左闭右开 [left, right)），
    // 减一即 floor(sqrt(x))；用 long long 防止 mid*mid 溢出
    int mySqrt(int x) {
        long long left = 0, right = (long long)x + 1;
        while (left < right) {
            long long mid = left + (right - left) / 2;
            if (mid * mid > x) right = mid;   // 平方超了，mid 可能是分界（蓝）
            else left = mid + 1;              // 平方没超，还能更大（红）
        }
        return (int)(left - 1);
    }
};
// @lc code=end
// ... existing code ...
// @lc code=end



/*
// @lcpr case=start
// 4\n
// @lcpr case=end

// @lcpr case=start
// 8\n
// @lcpr case=end

 */

