/*
 * @lc app=leetcode.cn id=204 lang=cpp
 *
 * [204] 计数质数
 */

// @lc code=start
class Solution {
public:
    bool prime(int n) {
        // 注意i*i <=n 的写法
        for(int i=2; i*i <=n; i++) {
            if(n % i == 0)
                return false;
        }
        return true;
    }
    int countPrimes(int n) {
        int res = 0;
        vector<int> map(n+1, 0); // 所有的数都是质数
        for(int i=2; i<n; i++) {
            if(map[i] == 0) {  
                res++;
                // 质数的2,3..倍数跟定不是质数
                for(int j=2; i*j < n; j++) {   // i*j 一定不是质数
                    map[i*j] = 1;
                }
            }
        }
        return res;
    }
};
// @lc code=end

