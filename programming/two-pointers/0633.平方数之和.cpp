// [633] 平方数之和
// 模板一：对撞指针，在 [0, sqrt(c)] 上找 a^2 + b^2 == c
class Solution {
public:
    bool judgeSquareSum(int c) {
        long left = 0, right = (long)sqrt(c); // 右界从 sqrt(c) 出发即可
        while (left <= right) {               // a == b 也合法，用 <=
            long sum = left * left + right * right;
            if (sum == c)  return true;
            else if (sum < c) left++;   // 平方和太小，左指针右移才可能变大
            else right--;               // 平方和太大，右指针左移
        }
        return false;
    }
};
