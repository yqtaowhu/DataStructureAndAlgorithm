/*
 * @lc app=leetcode.cn id=3918 lang=cpp
 * @lcpr version=30204
 *
 * [3918] 数与其逆序数之间的质数和
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
private:
    // 预处理的质数标记数组
    vector<bool> is_prime;
    
    // 埃拉托斯特尼筛法预处理质数
    void sieve(int max_val) {
        is_prime.assign(max_val + 1, true);
        is_prime[0] = is_prime[1] = false;
        
        for (int i = 2; i * i <= max_val; ++i) {
            if (is_prime[i]) {
                for (int j = i * i; j <= max_val; j += i) {
                    is_prime[j] = false;
                }
            }
        }
    }

public:
    int sumOfPrimesInRange(int n) {
        int rev = reverse(n);
        int right = max(n, rev);
        
        // 动态预处理质数
        sieve(right);
        
        int sum = 0;
        int left = min(n, rev);
        
        for (int i = left; i <= right; ++i) {
            if (is_prime[i]) {
                sum += i;
            }
        }
        return sum;
    }
    
private:
    int reverse(int n) {
        int rev = 0;
        while (n > 0) {
            rev = rev * 10 + n % 10;
            n /= 10;
        }
        return rev;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 13\n
// @lcpr case=end

// @lcpr case=start
// 10\n
// @lcpr case=end

// @lcpr case=start
// 8\n
// @lcpr case=end

 */

