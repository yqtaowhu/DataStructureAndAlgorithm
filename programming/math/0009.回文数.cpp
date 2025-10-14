/*
 * @lc app=leetcode.cn id=9 lang=cpp
 *
 * [9] 回文数
 */

// @lc code=start
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0 || x && x % 10 == 0) return false;
        int s = 0;
        while (s <= x) {
            s = s * 10 + x % 10;
            if (s == x || s == x / 10) return true; // 分别处理整数长度是奇数或者偶数的情况
            x /= 10;
        }
        return false;
    }
};

/*
bool isPalindrome(int x) {
    // 解法1： long long int 
	if (x < 0 || (x != 0 && x % 10 == 0)) {
		return false;
	}
	long long result = 0;   //using long long it can not be overflow
	int temp = x;
	while (temp)      //revere the num;
	{
		result = result * 10 + temp % 10;
		temp /= 10;
		if (result>INT_MAX)    //if overflow ,it must be return false
			return false;
	}
	return x ==result;
}
*/
// @lc code=end