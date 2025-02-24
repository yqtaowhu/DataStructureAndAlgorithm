class Solution {
public:
    int maxVowels(string s, int k) {
        int size = s.size();
        if (size < k) return 0;
        int res = 0, window_res = 0;
        // 初始化满足条件的窗口
        for(int i=0; i < k - 1; i++) {
            char c = s[i];
            if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                window_res += 1;
            }
        }
        for(int i=k-1; i < size; i++) {
            // 插入
            char c = s[i];
            if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                window_res += 1;
            }
            // 更新
            res = max(res ,window_res);
            // 删除
            c = s[i-k+1];
            if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                window_res -= 1;
            }
        }
        return res;
    }
};