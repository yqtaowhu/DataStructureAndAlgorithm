// 滑动窗口，收缩的条件要明确

class Solution {
public:
string minWindow(string s, string t) {
    unordered_map<char, int> need, hash;
    int s_size = s.size(), t_size = t.size();
    int need_cnt = 0, match = 0;
    for(int i=0; i < t_size; i++) {
        need[t[i]]++;
    }
    int beg = 0, end = 0, min_len=INT_MAX;
    int start = 0;
    while(end < s_size) {
        char c = s[end];
        if(need.count(c)) {
            hash[c]++;
            if (need[c] == hash[c]) {
                match++;
            }
        }
        end++;
        // 满足条件后，才进行窗口的减少
        while (match == need.size()) {
            if(end-beg < min_len) {
                start = beg;
                min_len = end-beg;
            }
            char c2 = s[beg];
            if(need.count(c2)) {
                // 这里注意条件, 都统一写成==
                if(hash[c2] == need[c2]) {
                    match--;
                }
                hash[c2]--;
            }
            beg++;
        }
    }
    return  min_len == INT_MAX ? "" : s.substr(start, min_len);
}
};