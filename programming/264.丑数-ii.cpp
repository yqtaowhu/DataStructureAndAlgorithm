/*
 * @lc app=leetcode.cn id=264 lang=cpp
 *
 * [264] 丑数 II
 */

// @lc code=start
class Solution {
public:
    /*
        int nthUglyNumber(int n) {
        if(n <= 0) return 0;
        if(n == 1) return 1;
        // 后面一个丑数一定是前一个丑叔*2，3，5中的一个得到的。
        int t2 = 0, t3 = 0, t5 = 0;
        vector<int> dp(n,1);
        for(int i=1; i<n; i++) {
            dp[i] = min(dp[t2]*2, min(dp[t3]*3, dp[t5]*5));
            if(dp[i] == dp[t2]*2) {
                t2++;
            }
            if(dp[i] == dp[t3]*3) {
                t3++;
            }
            if(dp[i] == dp[t5]*5) {
                t5++;
            }
            
        }
        return dp[n-1];
    }
    */
    int nthUglyNumber(int n) {
        priority_queue <double,vector<double>,greater<double> > q; // 小根堆
        double answer=1;
        for (int i=1; i<n; ++i) {
            q.push(answer*2);
            q.push(answer*3);
            q.push(answer*5);
            answer=q.top();
            q.pop();
            while (!q.empty() && answer==q.top())
                q.pop();
        }
        return answer;
    }
};
// @lc code=end

