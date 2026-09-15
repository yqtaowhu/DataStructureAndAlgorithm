/*
 * @lc app=leetcode.cn id=3963 lang=cpp
 * @lcpr version=30204
 *
 * [3963] 构造恰好一条路径的网格
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
    vector<string> createGrid(int m, int n) {
        vector<string> ans(m);
        ans[0].resize(n, '.');
        for (int i = 1; i < m; i++) {
            ans[i].resize(n, '#');
            ans[i][n - 1] = '.';
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 2\n3\n
// @lcpr case=end

// @lcpr case=start
// 3\n3\n
// @lcpr case=end

// @lcpr case=start
// 1\n4\n
// @lcpr case=end

 */

