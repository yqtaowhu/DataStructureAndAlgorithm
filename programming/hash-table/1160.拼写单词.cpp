/*
 * @lc app=leetcode.cn id=1160 lang=cpp
 *
 * [1160] 拼写单词
 */

// @lc code=start
class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        unordered_map<char, int> chars_cnt;
        for (char c : chars)
            ++chars_cnt[c];
        int ans = 0;
        for (string word : words) {
            unordered_map<char, int> word_cnt;
            for (char c : word)
                ++word_cnt[c];
            bool is_ans = true;
            for (char c : word)
                if (chars_cnt[c] < word_cnt[c]) {
                    is_ans = false;
                    break;
                }
            if (is_ans)
                ans += word.size();
        }
        return ans;
    }
};
// @lc code=end

