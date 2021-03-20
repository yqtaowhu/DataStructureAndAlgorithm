/*
 * @lc app=leetcode.cn id=605 lang=cpp
 *
 * [605] 种花问题
 */

// @lc code=start
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        // 贪心的方法
        // 不为空地，跳两格
        int size = flowerbed.size();
        for(int i=0; i<size && n; i+=2) {
            // 当前为空地
            if(flowerbed[i] == 0) {
                // 当前为空地，且是最后一个，一定可以种的, 种下后要跳两格
                if(i == size-1 || flowerbed[i+1] == 0) {
                    n--;
                } else {  // 如果后一个也种了花，则要跳3格
                    i++;
                }
            }
        }
        return n == 0;
    }
};
// @lc code=end

