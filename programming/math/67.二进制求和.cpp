/*
 * @lc app=leetcode.cn id=67 lang=cpp
 *
 * [67] 二进制求和
 */

// @lc code=start
class Solution {
public:
    string addBinary(string a, string b) {
       int m=a.size(), n=b.size(), carry=0;
       string res="";
       int i=m-1,j=n-1;
       while(i>=0 || j>=0 || carry) {
           cout<<i<<endl;
           cout<<j<<endl;
           int num1 = i>=0 ? a[i]-'0':0;
           int num2 = j>=0 ? b[j]-'0':0;
           int sum = num1 + num2 +carry;
           res.insert(res.begin(), sum%2+'0');
           carry = sum/2;
           i--;j--;
       }
       return res;
    }
};
// @lc code=end

