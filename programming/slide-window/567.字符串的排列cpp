// 统一的模板
// 3 & 76 & 438 & 567

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> need, window;
        for (char c : s1) need[c]++;

        int left = 0, right = 0;
        int valid = 0;
        while (right < s2.size()) {
            char c = s2[right];
            right++;
            // 进行窗口内数据的一系列更新
            if (need.count(c)) {
                window[c]++;
                if (window[c] == need[c]) 
                    valid++;
            }
            // 判断左侧窗口是否要收缩
            while (right - left >= s1.size()) {
                // 当窗口符合条件时，把起始索引加入 res
                if (valid == need.size())
                    return true;
                char d = s2[left];
                left++;
                // 进行窗口内数据的一系列更新
                if (need.count(d)) {
                    if (window[d] == need[d])
                        valid--;
                    window[d]--;
                }
            }
        
        }
        return false;
    }
    
};