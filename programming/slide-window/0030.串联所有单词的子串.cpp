/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0030.串联所有单词的子串.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taoyanqi <taoyanqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 12:47:25 by taoyanqi          #+#    #+#             */
/*   Updated: 2025/10/22 12:47:26 by taoyanqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int word_len = words[0].size(); // 一个单词的长度
        int window_len = word_len * words.size(); // 所有单词的总长度，即窗口大小

        // 目标：窗口中的单词出现次数必须与 target_cnt 完全一致
        unordered_map<string, int> target_cnt;
        for (auto& w : words) {
            target_cnt[w]++;
        }

        vector<int> ans;
        // 枚举窗口起点，做 word_len 次滑动窗口
        for (int start = 0; start < word_len; start++) {
            unordered_map<string, int> cnt;
            int overload = 0;
            // 枚举窗口最后一个单词的右端点+1
            for (int right = start + word_len; right <= s.size(); right += word_len) {
                // 1. in_word 进入窗口
                string in_word = s.substr(right - word_len, word_len);
                // 下面 cnt[in_word]++ 后，in_word 的出现次数过多
                if (cnt[in_word] == target_cnt[in_word]) {
                    overload++;
                }
                cnt[in_word]++;

                int left = right - window_len; // 窗口第一个单词的左端点
                if (left < 0) { // 窗口大小不足 window_len
                    continue;
                }

                // 2. 更新答案
                // 如果没有超出 target_cnt 的单词，那么也不会有少于 target_cnt 的单词
                if (overload == 0) {
                    ans.push_back(left);
                }

                // 3. 窗口最左边的单词 out_word 离开窗口，为下一轮循环做准备
                string out_word = s.substr(left, word_len);
                cnt[out_word]--;
                if (cnt[out_word] == target_cnt[out_word]) {
                    overload--;
                }
            }
        }

        return ans;
    }
};