// [680] 验证回文串 II
// 模板一：对撞指针，遇到不匹配时允许删除一个字符再验证
class Solution {
public:
    bool validPalindrome(string s) {
        int left = 0, right = s.size() - 1;
        while (left < right) {
            if (s[left] != s[right]) {
                // 删左或删右，两种子串任一回文即可
                return check(s, left + 1, right) || check(s, left, right - 1);
            }
            left++, right--;
        }
        return true;
    }
private:
    bool check(const string& s, int left, int right) {
        while (left < right) {
            if (s[left++] != s[right--]) return false;
        }
        return true;
    }
};
