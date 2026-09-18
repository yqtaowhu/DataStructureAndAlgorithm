/*
 * @lc app=leetcode.cn id=135 lang=cpp
 *
 * [135] 分发糖果
 */

// @lc code=start
class Solution {
public:
    // 1 0 2
    // 1. 初始化  1 1 1
    // 2. 从左到右遍历  1 1 2
    // 3. 从右到左遍历  2 1 2
    int candy(vector<int>& ratings) {
        int size = ratings.size();
        if(size < 2) {
            return size;
        }
        vector<int> v(size, 1);
        // 从左到右遍历,比前一个大值，值加1
        for(int i=1; i < size; i++) {
            if(ratings[i] > ratings[i-1]) {
                v[i] = v[i-1] + 1;
            }
        }
        // 从右到左， 比后一个大是，如果本身值小则加1
        for(int i=size-2; i>=0; i--) {
            if(ratings[i] > ratings[i+1] && v[i] <= v[i+1]) {
                v[i] = v[i+1] + 1;
            }
        }
        return accumulate(v.begin(), v.end(), 0);
    }
};
// @lc code=end

