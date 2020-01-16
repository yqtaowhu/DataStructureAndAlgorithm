/*
 * @lc app=leetcode.cn id=28 lang=cpp
 *
 * [28] 实现 strStr()
 */

// @lc code=start
class Solution {
public:
    // 简单双指针法
    int strStr_1(string haystack, string needle) {
        int n1=haystack.size(),n2=needle.size();
        if(n2==0) return 0;
        if (n1<n2) return -1;
        int i=0,j=0;
        // 注意只需要 i<n1-n2即可
        // 下面的写法很精髓，简单
        for (i=0;i<=n1-n2;i++) {
            for (j=0;j<n2;j++) {
                if (needle[j]!=haystack[i+j]) 
                    break;
            }
            if (j==n2) return i;
        }
        return -1;
    }
};
// @lc code=end

