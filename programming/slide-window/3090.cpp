
// 和2958一样，就是改个条件
class Solution {
public:
    int maximumLengthSubstring(string s) {
        int size = s.size(), res = 0;
        unordered_map<int, int> map;
        for(int i=0, j=0; j < size; j++) {
            map[s[j]]++;
            // 窗口不符合条件
            while(map[s[j]] > 2) {
                map[s[i++]]--;
            }
            res = max(res, j-i+1);
        }
        return res; 
    }
};