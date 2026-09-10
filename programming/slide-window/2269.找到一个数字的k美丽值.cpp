// 2269. 找到一个数字的 K 美丽值
// 模板：定长窗口（在数字字符串上滑，窗口长度 k）
// 判定：子串转成的整数 val 满足 val != 0 && num % val == 0
// 滑窗维护 val：入 = val*10 + 新位；出 = 减掉最高位 × 10^(k-1)，比每次 substr 更快
// 坑：val 为 0（如子串 "00"）时必须跳过，否则取模除零

class Solution {
public:
    int divisorSubstrings(int num, int k) {
        string s = to_string(num);
        int n = s.size(), ans = 0, val = 0, base = 1;
        for (int i = 0; i < k - 1; i++) base *= 10;      // 窗口最高位的权值 10^(k-1)
        for (int right = 0; right < n; right++) {
            val = val * 10 + (s[right] - '0');           // 1. 入
            if (right < k - 1) continue;                 // 窗口未满
            if (val != 0 && num % val == 0) ans++;       // 2. 更新
            val -= (s[right - k + 1] - '0') * base;      // 3. 出：去掉最高位
        }
        return ans;
    }
};


class Solution {
public:
    int divisorSubstrings(int num, int k) {
        string s = to_string(num);
        int ans = 0;
        for (int i = k; i <= s.size(); i++) {
            int x = stoi(s.substr(i - k, k)); // 长为 k 的子串
            if (x > 0 && num % x == 0) { // 子串能整除 num
                ans++;
            }
        }
        return ans;
    }
};