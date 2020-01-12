/*
 * @lc app=leetcode.cn id=12 lang=cpp
 *
 * [12] 整数转罗马数字
 */

// @lc code=start
class Solution {
public:
    //由于加减的不同，所以讲IV这种看出一个新的字符，然后从大到小使用较大的字符
    string intToRoman(int num) {
        string symbol[] = { "M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I" };
        int value[] = { 1000,900,500,400, 100, 90,  50, 40,  10, 9,   5,  4,   1 };
        string result;
        // 循环symbol
        for (int i = 0; num != 0; i++) {
            // 重复使用symbol，由于构造新的字符，所以满足不重复使用4个的原理
            while (num >= value[i]) {
                num -= value[i];
                result += symbol[i];
            }
        }
        return result;
    }
};
// @lc code=end

