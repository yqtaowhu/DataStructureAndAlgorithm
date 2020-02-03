/*
 * @lc app=leetcode.cn id=43 lang=cpp
 *
 * [43] 字符串相乘
 */

// @lc code=start
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        int m=num1.size(), n=num2.size();
        vector<int> A,B,res(m+n,0);
        // 将低位放到数组低位
        for(int i=m-1;i>=0;i--) A.push_back(num1[i]-'0');
        for(int i=n-1;i>=0;i--) B.push_back(num2[i]-'0');
        // 核心代码，循环遍历
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                res[i+j] += A[i]*B[j];
                res[i+j+1] += res[i+j] / 10; //进位
                res[i+j] %= 10;
            }
        }
        //去掉先导0
        while(res.size()>1 && res.back()==0) res.pop_back();
        string c;
        for(int i=res.size()-1; i>=0; i--) {
            c += res[i] + '0';
        }
        return c;
    }
};


// @lc code=end

