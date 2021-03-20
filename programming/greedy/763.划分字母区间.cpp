/*
 * @lc app=leetcode.cn id=763 lang=cpp
 *
 * [763] 划分字母区间
 */

// @lc code=start
class Solution {
public:
    vector<int> partitionLabels(string S) {
        //用end 和 start来划分现在的一个区间
        int map[26], length = S.size(), end = 0, start = 0;
        vector<int> ans;
        
        //记录字符串中每个字母最后出现的位置
        for(int i = 0;i < length;i++){
            map[S[i]-'a'] = i;
        }

        //遍历字符串
        for(int i = 0;i < length;i++) {
            end = max(end, map[S[i]-'a']); //贪心策略：每次刷新到最小的但是要全部包含字母的位置
            if(i == end) { //如果指针i找到了end的话，就代表这个区间已经搜索完毕
                ans.push_back(end-start+1);
                start = end + 1;
            }
        }
        return ans;
    }
};
// @lc code=end

