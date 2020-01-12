/*
 * @lc app=leetcode.cn id=8 lang=cpp
 *
 * [8] 字符串转换整数 (atoi)
 */

// @lc code=start
#include <string>
#include <iostream>

using namespace std;
class Solution {
public:
    int myAtoi(string str) {
        if(str.size()<=0) return 0;
        int i = 0;
        // 去除空格
        while(i < str.size() && str[i] == ' ') i++;

        int sign = 1;
        //不是+，-，或者数字，则有误
        if(str[i]!='+' && str[i]!='-'&&!isdigit(str[i]))
            return 0;
        if(str[i] == '+') {
            sign = 1;
            i++;
        } else if (str[i] == '-') {
            sign = -1;
            i++;
        }
        long long int res = 0;
        while(i< str.size() && isdigit(str[i])) {
            int digit = str[i++] - '0';
            //cout<<digit<<endl;
            res = res*10 + digit;
            if(sign*res > INT_MAX) {
                return INT_MAX;
            } else if (sign*res < INT_MIN) {
                return INT_MIN;
            }
        }
        return sign*res;   
    }
};
// @lc code=end

