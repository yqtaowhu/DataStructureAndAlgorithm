class Solution {
public:
    //pre：上一个子串数值 pos：上一个子串结束位置
    bool dfs(unsigned long long pre, string s, int pos, int n) {
        if (pos == n - 1) return true;  //划分到最后一个位置，划分成功
        if (pre == 0) { //前面子串数值为0，后边若全为0则成功划分（后边0全归到上一个子串），否则失败
            for (int i = pos + 1; i < n; i++) {
                if (s[i] != '0') return false;
            }
            return true;
        }
        unsigned long long cur = 0; //当前子串数值
        for (int i = pos + 1; i < n; i++) { //从pos + 1开始划分下一个子串
            cur *= 10 + 0LL;
            cur += s[i] - '0' + 0LL;
            if (cur == pre - 1) return dfs(cur, s, i, n);   //满足cur == pre - 1，划分下一个子串
            else if (cur >= pre) return false;  //cur >= pre时，再往后划分只会大于等于pre，划分失败
        }
        return false;   //没有划分成功就是划分失败
    }
    bool splitString(string s) {
        int i = 0, n = s.size(); 
        for (i; i < n; i++) {    //去除s前导0，排除掉全0的情况
            if (s[i] != '0') break;
        }
        unsigned long long pre = 0; //第一个子串数值（最多20位数字）
        for (i; i < n - 1; i++) {   //枚举第一个子串，长度为1 ~ n - 1（至少划分2个子串）
            pre *= 10 + 0LL;
            pre += s[i] - '0' + 0LL;
            if (dfs(pre, s, i, n) == true) return true; //能划分到最后，说明可以划分
        }
        return false;   //没有划分成功就是划分失败
    }
};