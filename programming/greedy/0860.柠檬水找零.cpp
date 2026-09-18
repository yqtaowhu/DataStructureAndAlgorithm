/*
 * @lc app=leetcode.cn id=860 lang=cpp
 *
 * [860] 柠檬水找零
 */

// @lc code=start
class Solution {
public:
    // 贪心：维护手头 5 元和 10 元的张数。
    // 找 15 元时优先用「10 + 5」而不是「5+5+5」，因为 5 元更万能、要省着用。
    bool lemonadeChange(vector<int>& bills) {
        int five = 0, ten = 0;
        for (int b : bills) {
            if (b == 5) {
                five++;
            } else if (b == 10) {
                if (five == 0) return false; // 找不出 5 元
                five--; ten++;
            } else { // b == 20，需找 15 元
                if (ten > 0 && five > 0) { ten--; five--; } // 优先 10+5
                else if (five >= 3) { five -= 3; }          // 退而求其次 5+5+5
                else return false;
            }
        }
        return true;
    }
};
// @lc code=end
