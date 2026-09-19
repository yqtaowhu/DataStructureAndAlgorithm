/*
 * @lc app=leetcode.cn id=3908 lang=cpp
 * @lcpr version=30204
 *
 * [3908] 有效数字整数
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
    bool validDigit(int n, int x) {
        int exist = 0;
        while(n > 9) {
            int t = n % 10;
            if(t == x) {
                exist = 1;
            }
            n /= 10;
        }
        return exist == 1 && n != x;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 101\n0\n
// @lcpr case=end

// @lcpr case=start
// 232\n2\n
// @lcpr case=end

// @lcpr case=start
// 5\n1\n
// @lcpr case=end

 */

