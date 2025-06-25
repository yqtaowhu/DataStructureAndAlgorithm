/*
 * @lc app=leetcode.cn id=128 lang=cpp
 *
 * [128] 最长连续序列
 */

// @lc code=start
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // 100,4,200,1,3,2
        // 不断的更新边界值, 
        // 100 l=0,r=0 -> len=1
        // 4 l=0,r=0,len=1
        // 200 l=0,r=0,len=1
        // 1 l=0,r=0,len=1
        // 3 l=0,r=1,len=2   3,4
        // 2 l=1,r=2, len=4
        int res = 0;
        unordered_map<int, int> map;
        for(auto n : nums) {
            if(map.find(n) == map.end()) {
                int l = map.count(n-1) == 1 ? map[n-1] : 0;
                int r = map.count(n+1) == 1 ? map[n+1] : 0;
                int len = r + l + 1;
                map[n] = len;
                map[n-l] = len;   // 特别注意
                map[n+r] = len;
                res = max(len, res);

            } else {
                // 出现过的元素，不会重新更新左右边界
                continue;
            }
        }
        return res;
    }
};
// @lc code=end

