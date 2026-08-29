class Solution {
public:
    vector<int> ans;//记录答案
    string cur;//记录当前路径
    void dfs(int i, int n, int k) {
        // 如果当前字符串长度达到 n，将其转换为整数并加入结果
        if (cur.size() == n) {
            ans.emplace_back(stoi(cur));
            return;
        }
        // 这里类似选与不选的思路 +k 或-k
        // 尝试添加 i + k
        if (i + k < 10) {
            cur += to_string(i + k);
            dfs(i + k, n, k);
            cur.pop_back();
        }
        // 特殊处理 k = 0 的情况，避免重复计算 如果不判断 则答案会有 i + 0 和 i - 0 两种重复情况
        if (k != 0 && i - k >= 0) {
            cur += to_string(i - k);
            dfs(i - k, n, k);
            cur.pop_back();
        }
    }
    vector<int> numsSameConsecDiff(int n, int k) {
        // 遍历起始数字
        for (int i = 0; i < 10; ++i) {
            // 当 n > 1 且起始数字为 0 时，跳过，因为不能有前导 0
            if (n > 1 && i == 0) continue;
            cur = to_string(i);
            dfs(i, n, k);
        }
        return ans;
    }
};