/*
 * @lc app=leetcode.cn id=179 lang=cpp
 *
 * [179] 最大数
 */

// @lc code=start
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        string res="";
        if(nums.empty()) return res;
        // 定义排序方式
        sort(nums.begin(),nums.end(),[](const int& a,const int& b)
            {return to_string(a)+to_string(b)>to_string(b)+to_string(a);});
        for (auto c:nums) res+=to_string(c);
        return (nums[0]==0) ? "0" : res;
    }
};
// @lc code=end

