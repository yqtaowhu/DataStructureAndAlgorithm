/*
 * @lc app=leetcode.cn id=3969 lang=cpp
 * @lcpr version=30204
 *
 * [3969] 求和后首尾数字相同的有效子数组 I
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
    int countValidSubarrays(vector<int>& nums, int x) {
        int n = nums.size();
        int ans = 0;

        // 枚举子数组的左右端点
        for (int i = 0; i < n; i++) {
            long long sum = 0;
            for (int j = i; j < n; j++) {
                sum += nums[j];
                // 计算 sum 的最低位
                if (sum % 10 != x) {
                    continue;
                }
                // 计算 sum 的最高位
                auto s = sum;
                while (s > 9) {
                    s /= 10;
                }
                if (s == x) {
                    ans++;
                }
            }
        }

        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,100,1]\n1\n
// @lcpr case=end

// @lcpr case=start
// [1]\n2\n
// @lcpr case=end

 */

