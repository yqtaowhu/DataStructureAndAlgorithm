/*
 * @lc app=leetcode.cn id=2389 lang=cpp
 * @lcpr version=30204
 *
 * [2389] 和有限的最长子序列
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
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        // 排序不影响结果
        sort(nums.begin(), nums.end());
        // 1 2 4 5   -> 0 1 3 7 12 -> 二分查找
        vector<int> fsum(n+1, 0);
        for(int i=0; i < n; i++) {
            fsum[i+1] = fsum[i] + nums[i];
        }
        int m = queries.size();
        vector<int> res(m, 0);
        for(int i=0; i < m; i++) {
            int left = upper_bound(fsum.begin(), fsum.end(), queries[i]) - fsum.begin();
            res[i] = left - 1;
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [4,5,2,1]\n[3,10,21]\n
// @lcpr case=end

// @lcpr case=start
// [2,3,4,5]\n[1]\n
// @lcpr case=end

 */

