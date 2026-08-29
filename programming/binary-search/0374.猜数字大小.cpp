/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int left = 0, right = n;   // 左闭右开，候选范围 [1, n]
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (guess(mid) <= 0) {     // mid >= pick，mid 可能是答案
                right = mid;
            } else {                   // mid < pick，mid 一定不是答案
                left = mid + 1;
            }
        }
        return left;
    }
};