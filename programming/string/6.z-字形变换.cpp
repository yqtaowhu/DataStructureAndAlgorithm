/*
 * @lc app=leetcode.cn id=6 lang=cpp
 *
 * [6] Z 字形变换
 */

// @lc code=start
class Solution {
public:
    // 方法1：暴力方法，用数组存储
    string convert(string s, int numRows) {
       int length = s.size();
       if(length <= numRows) return s;
       if(numRows <= 1) return s;
       vector<string> vec(numRows);
       int topToDown = 1, row = 0;
       for(int i=0; i< length; i++) {
            //cout<<row<<endl;
            vec[row] += s[i];
            if(row >= numRows -1) {
               topToDown = -1;
            } else if(row <= 0) {
                topToDown = 1;
            }
            row = row + topToDown;
       }
       string res;
       for(auto &str:vec) {
           res += str;
       }
       return res; 
    }
};
// @lc code=end

/*
参考资料: https://www.acwing.com/solution/LeetCode/content/75/
方法2： 找规律
0     6       12
1   5 7    11 ..
2 4   8 10
3     9

class Solution {
public:
    string convert(string s, int numRows) {
        string res;
        if (numRows == 1) return s;
        for (int j = 0; j < numRows; j ++ )
        {
            if (j == 0 || j == numRows - 1)
            {
                for (int i = j; i < s.size(); i += (numRows-1) * 2)
                    res += s[i];
            }
            else
            {
                for (int k = j, i = numRows * 2 - 1 - j - 1;
                        i < s.size() || k < s.size();
                        i += (numRows - 1) * 2, k += (numRows - 1) * 2)
                {
                    if (k < s.size()) res += s[k];
                    if (i < s.size()) res += s[i];
                }
            }
        }
        return res;
    }
};
*/