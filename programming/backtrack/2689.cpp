class Solution {
public:
    // dfs(81, 0, 0, 9)
    bool dfs(string &s, int pos, int tot, int target) {
        // 终止条件，判断
        if (pos == s.size()) {
            return tot == target;
        } 

        // 分割子串并计算sum, 和累计前面的和
        int sum = 0;
        for (int i = pos; i < s.size(); i++) {
            sum = sum * 10 + s[i] - '0';
            if (sum + tot > target) {
                break;
            }
            if (dfs(s, i + 1, sum + tot, target)) {
                return true;
            }
        }
        return false;
    }
    
    int punishmentNumber(int n) {
        int res = 0;
        for (int i = 1; i <= n; i++) {
            string s = to_string(i * i);
            if (dfs(s, 0, 0, i)) {
                res += i * i;
            }
        }
        return res;
    }
};