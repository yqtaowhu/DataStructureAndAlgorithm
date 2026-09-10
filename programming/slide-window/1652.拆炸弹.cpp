// 1652. 拆炸弹
// 模板：定长窗口（环形），窗口长度 = |k|
// k>0：code[i] 换成它后面 k 个数字之和，窗口 [i+1, i+k]
// k<0：换成前面 |k| 个数字之和，窗口 [i-|k|, i-1]；k==0：全部置 0
// 环形技巧：下标一律对 n 取模（负数先 +n 再 %n）；相邻 i 的窗口只挪一格 ⇒ 出左端、入右端

class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int> ans(n, 0);
        if (k == 0) return ans;
        int kk = k > 0 ? k : -k;
        int lo = k > 0 ? 1 : -kk;                  // i=0 时窗口左端相对 i 的偏移
        int hi = k > 0 ? kk : -1;                  // i=0 时窗口右端相对 i 的偏移
        auto at = [&](int idx) { return code[((idx % n) + n) % n]; };   // 环形取值
        int sum = 0;
        for (int j = lo; j <= hi; j++) sum += at(j);   // 先算 i=0 的窗口和
        ans[0] = sum;
        for (int i = 1; i < n; i++) {
            sum -= at(i + lo - 1);                 // 出：上一窗口的左端
            sum += at(i + hi);                     // 入：新窗口的右端
            ans[i] = sum;                          // 更新
        }
        return ans;
    }
};
