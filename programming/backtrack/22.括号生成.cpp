// 本质上来说，我们需要在 0,1,2,…,2n−1 中选 n 个数（位置），填入左括号。其余 n 位置填入右括号。
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string path(n * 2, 0); // 所有括号长度都是一样的 2n

        // 目前填了 left 个左括号，right 个右括号
        auto dfs = [&](this auto&& dfs, int left, int right) -> void {
            if (right == n) { // 填完 2n 个括号
                ans.emplace_back(path);
                return;
            }
            if (left < n) { // 可以填左括号
                path[left + right] = '('; // 直接覆盖
                dfs(left + 1, right);
            }
            if (right < left) { // 可以填右括号
                path[left + right] = ')'; // 直接覆盖
                dfs(left, right + 1);
            }
        };

        dfs(0, 0); // 一开始没有填括号
        return ans;
    }
};

