/*
 * @lc app=leetcode.cn id=14 lang=cpp
 *
 * [14] 最长公共前缀
 */

// @lc code=start
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        // 暴力枚举就行
        if (strs.size() == 0)
            return "";
        int min_length = strs[0].length();
        for (int i = 1; i < strs.size(); i++)
            min_length = min(min_length, int(strs[i].length()));

        for (int s = 1; s <= min_length; s++) {
            char c = strs[0][s - 1];
            for (int i = 1; i < strs.size(); i++)
                if (strs[i][s - 1] != c)
                    return strs[0].substr(0, s - 1);
        }
        return strs[0].substr(0, min_length);
    }
};
// @lc code=end

/*
使用substr，取不同长度的前缀
string longestCommonPrefix(vector<string>& strs) {
	int n = strs.size();
	string res;
	if (n <= 0) return res;
	for (int i = 1; i <= strs[0].size(); i++) {
		string temp = strs[0].substr(0, i);
		bool match = true;
		for (int j = 1; j<strs.size(); j++) {
			if (i>strs[j].size() || temp != strs[j].substr(0, i)) {
				match = false;
				break;
			}
		}
		if (!match) return res;
		res = temp;
	}
	return res;
}
*/

