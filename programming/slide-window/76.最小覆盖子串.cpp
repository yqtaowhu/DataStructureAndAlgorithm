/*
 * @lc app=leetcode.cn id=76 lang=cpp
 *
 * [76] 最小覆盖子串
 */

// @lc code=start
class Solution {
public:
    /*
        滑动窗口题型,两个指针
        1. 首先l,r=0, 
        2. l不变r++, 直到满足条件
        3. 满足条件后，一直缩小窗口，l++，直到不满足
        4. 此时调到2
        所有，是两个循环的实现，一个while(right<size),第二个是满足条件条件的while循环
        S = "ADOBECODEBANC", T = "ABC"
             l    r
        
    */
    string minWindow(string s, string t) {
        int start=0, min_len = INT_MAX; //用来计算最小的起点和长度
        int left=0, right=0; //双指针
        unordered_map<char, int> needs, windows; 
        for(auto c:t) needs[c]++;
        int match = 0;

        while(right<s.size()) {
            // right指向的是需求的字符
            char c1 = s[right];
            if(needs.count(c1)) {
                windows[c1]++;
                // 当前窗口满足条件
                if(windows[c1] == needs[c1]) {
                    match++;                    
                }
            }
            right++;
            // 满足条件，缩小窗口
            while(match == needs.size()) {
                if(right-left < min_len) {
                    start = left;
                    min_len = right-left;
                }
                // 移动left
                char c2 = s[left];
                if(needs.count(c2)) {
                    windows[c2]--;
                    if(windows[c2] < needs[c2]) {
                        match--;
                    }
                }
                left++;
            }
        }
        return min_len == INT_MAX ? "" : s.substr(start, min_len);
    }
};
// @lc code=end


// class Solution {
//     public:
//     string minWindow(string s, string t) {
//         unordered_map<char, int> need, hash;
//         int count = 0, min_len = INT_MAX, beg = 0, need_count=0;
//         int s_size = s.size(), t_size = t.size();
//         for(int i=0; i < t_size; i++) {
//             if(need.find(t[i]) == need.end()) {
//                 need_count += 1;
//             }
//             need[t[i]]++;
//         }
//         cout << "need" << need_count << endl;
//         for(int i=0; i < s_size; i++) {
//             int j = i;
//             hash.clear();
//             count = 0;
//             for(; j<s_size; j++) {
//                 char tmp = s[j];
//                 hash[tmp]++;
//                 //cout << "1 " << hash[tmp] << endl;
//                 if (need.find(tmp) != need.end()) {
//                     if(need[tmp] == hash[tmp]) {
//                         count += 1;
//                     }
//                 }
//                 if(count == need_count) {
//                     if(j-i+1 < min_len) {
//                         min_len = j - i + 1;
//                         beg = i;
//                     }
//                     break;
//                 }
//             }
//         }
//         if (min_len < INT_MAX) {
//             return s.substr(beg, min_len);
//         }
//         return "";
//     }
// };