/*
 * @lc app=leetcode.cn id=135 lang=cpp
 *
 * [135] 分发糖果
 */

// @lc code=start
class Solution {
public:
    int candy(vector<int>& ratings) {
        if(ratings.empty()) return 0;

        int m = ratings.size();
        vector<int> left(m,1), right(m,1);
        // 从左到右遍历
        for(int i=1; i<m; i++) {
            if(ratings[i] > ratings[i-1])
                left[i] = left[i-1] + 1;
        }
        // 从右到左遍历,同时记录结果
        int res = left[m-1];
        for(int i=m-2; i>=0; i--) {
            if(ratings[i] > ratings[i+1]) {
                right[i] = right[i+1] + 1;
            }
            res += max(left[i], right[i]);
        }
        return res;
        
    }
};
// @lc code=end

