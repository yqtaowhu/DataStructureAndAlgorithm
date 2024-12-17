/*
 * @lc app=leetcode.cn id=605 lang=cpp
 *
 * [605] 种花问题
 */

// @lc code=start
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int size = flowerbed.size();
        for(int i=0; i < size && n > 0; i++) {
            // 连续三个为0，考虑首位特殊情况
            //不考虑首位 i-1, i , i+1都为0
            //考虑首位 i==0, i, i+1为0， i==m-1,ii-1 为0
            if((i == 0 || flowerbed[i-1] == 0) && 
                (flowerbed[i] == 0) && 
                (i==size-1 || flowerbed[i+1] == 0)) {
                    n--;
                    i++; // 下一个位置肯定不能
                }
        }
        return n == 0;
    }
};
// @lc code=end

