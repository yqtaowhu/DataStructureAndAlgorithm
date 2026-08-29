
/*
给你一个字符数组 letters，该数组按 非递减顺序 排序，以及一个字符 target。letters 里至少有两个不同的字符。

返回 letters 中大于 target 的最小的字符。如果不存在这样的字符，则返回 letters 的第一个字符。
*/


// upper_bound
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int n = letters.size();
        int left = 0, right = n;
        // 找到第一个大于target
        while(left < right) {
            int mid = left + (right - left) / 2;
            if(letters[mid] > target) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left < n ? letters[left] : letters[0];
    }
};