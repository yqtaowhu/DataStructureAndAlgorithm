/*
 * @lc app=leetcode.cn id=945 lang=cpp
 *
 * [945] 使数组唯一的最小增量
 */

// @lc code=start
class Solution {
public:
    // 排序
    int minIncrementForUnique(vector<int>& A) {
        int count = 0;
        sort(A.begin(), A.end());
        for (int i = 1; i < A.size(); ++i) {
            int diff = A[i - 1] - A[i] + 1  ;    //diff表示后者需要比前者大1，所要进行的操作次数
            count  +=  max(0,  diff );
            A[i]   +=  max(0,  diff );
        }
        return count;
    }
    //计数
    /*
    int minIncrementForUnique(vector<int>& A) {
        int cnt[80000] = { 0 };
        for (int x: A) cnt[x]++;

        int ans = 0, taken = 0;

        for (int x = 0; x < 80000; ++x) {
            if (cnt[x] >= 2) {
                taken += cnt[x] - 1;
                ans -= x * (cnt[x] - 1);
            }
            else if (taken > 0 && cnt[x] == 0) {
                taken--;
                ans += x;
            }
        }

        return ans;
    }
    */
};
// @lc code=end

