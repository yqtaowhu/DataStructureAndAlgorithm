/*
 * @lc app=leetcode.cn id=128 lang=cpp
 *
 * [128] 最长连续序列
 */

// @lc code=start
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int> m;
        int res = 0;
        for(int i=0;i<nums.size();i++){
            int n = nums[i];
            if(m.find(n) == m.end()){
                int l = m.count(n-1) == 1 ? m[n-1] : 0;
                int r = m.count(n+1) == 1 ? m[n+1] : 0;
                int len = l + r + 1;
                m[n] = len;
                res = max(res,len);
                m[n-l] = len;  //特别注意更新边界值
                m[n+r] = len;
            }
            else
                continue;
        }
        return res;
    }
};
// @lc code=end

