/*
 * @lc app=leetcode.cn id=60 lang=cpp
 *
 * [60] 第k个排列
 */

// @lc code=start
class Solution {
public:
    // 回溯+剪枝
    // 参考： https://leetcode-cn.com/problems/permutation-sequence/solution/hui-su-jian-zhi-python-dai-ma-java-dai-ma-by-liwei/
    // 求解n的阶层
    int factorial(int n){
        int res = 1;
        while(n > 0){
            res *= n;
            n--;
        }
        return res;
    }

    string getPermutation(int n, int k) {
        string res="";
        vector<bool> is_used(n+1, false);
        dfs(is_used, res, n, k);
        return res;
    }
    void dfs(vector<bool> &is_used, string &res, int n, int k) {
        if(res.size() == n) {
            return;
        }
        // 选定一个数后，求剩下数的全排列个数 n=4, k=9
        // 例如选1后，剩下的全排列为6，表明以1为开始的全排列有6个,则可以进行剪枝
        int remain_fac = factorial(n - res.size() - 1);  
        for(int i=1; i<=n; i++) {
            if(is_used[i]) {
                continue;
            }
            // 剪枝
            if(remain_fac >0 && remain_fac < k ) {
                k -= remain_fac;
                continue;
            }
            res += i + '0';
            is_used[i] = true;
            dfs(is_used, res, n, k);
            // 不用将 is_used[i] = false, 因为第一个条件满足就是答案
        }
    }
};
// @lc code=end

