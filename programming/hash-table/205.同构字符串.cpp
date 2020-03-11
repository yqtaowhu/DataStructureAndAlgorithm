/*
 * @lc app=leetcode.cn id=205 lang=cpp
 *
 * [205] 同构字符串
 */

// @lc code=start
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char> map;
        for (int i=0;i<s.size();i++) {
            if (map.find(s[i])==map.end()) {               //如果没有找到这个映射
                map[s[i]]=t[i];                            //添加映射
                for (int j=0;j<i;j++) {                    //查找是否有重复映射
                    if (map[s[j]]==map[s[i]]) return false;//如果有重复，则为假
                }
            }
            else {                                         //如果有此映射
                if (map[s[i]]!=t[i]) return false;         //看是否相等
            }
        }
        return true;
    }
};
// @lc code=end

