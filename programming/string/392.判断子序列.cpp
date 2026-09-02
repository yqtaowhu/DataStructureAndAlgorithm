// 方法一：双指针遍历, 单次查询 O(m + n), 适合查询次数少的情况
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int m = s.size(), n = t.size();
        int i=0, j = 0;
        while(i < m && j < n) {
            if(s[i] == t[j]) {
                i++;
            }
            j++;
        }
        return i == m;
    }
};

/*
 * 方法二：预处理 + 二分查找, 大量 S 查询场景
 *
 * 场景：T 固定不变, 需要依次检查 k >= 10 亿个 S 是否为 T 的子序列。
 * 若用方法一, 总耗时 O(k * (m + n)), 每次都要完整扫描 T, 无法接受。
 *
 * 思路：只对 T 预处理一次 —— 记录每个字符在 T 中出现的全部位置(按下标递增),
 * 查询 s 时, 用一个 "当前匹配位置" pos, 对 s 的每个字符 c:
 *   在 c 的位置列表中二分查找第一个 > pos 的下标, 找到则更新 pos, 否则 s 不是子序列。
 *
 * 复杂度：预处理 O(n); 单次查询 O(m * log n)
 *         总耗时 O(n + k * m * log n), 相比 O(k * (m + n)) 大幅提升
 *
 * 空间：O(n) 存储 T 的位置列表
 */
class SubsequenceChecker {
    vector<vector<int>> pos;  // pos[c] = 字符 c 在 T 中出现的所有下标(递增)
public:
    // 预处理只做一次, 之后可服务任意多次查询
    SubsequenceChecker(const string& t) : pos(26) {
        for(int i = 0; i < (int)t.size(); i++) {
            pos[t[i] - 'a'].push_back(i);
        }
    }

    bool isSubsequence(const string& s) {
        int prev = -1;  // 上一个已匹配字符在 T 中的下标
        for(char c : s) {
            auto& p = pos[c - 'a'];
            // 在 p 中找第一个 > prev 的位置(严格大于, 保证子序列下标严格递增)
            auto it = upper_bound(p.begin(), p.end(), prev);
            if(it == p.end()) return false;  // 后面没有字符 c 可用了
            prev = *it;
        }
        return true;
    }
};

/*
 * 方法三：预处理 next 表(空间换时间的极致), 大量短 S 查询场景
 *
 * 思路：pre[i][c] = 从下标 i 开始(含), 字符 c 第一次出现的位置
 *   倒序递推: pre[i][c] = (t[i]==c) ? i : pre[i+1][c]
 * 查询时每个字符只需 O(1) 跳转, 不用二分。
 *
 * 复杂度：预处理 O(26 * n); 单次查询 O(m)
 *         总耗时 O(26n + k * m), 适合 s 很短、k 极大的场景
 *
 * 空间：O(26 * n), 空间开销是方法二的 26 倍, 需按内存预算权衡
 */
class SubsequenceChecker2 {
    vector<array<int, 26>> nxt;  // nxt[i][c]: 从 i 开始字符 c 第一次出现的位置, 无则 n
public:
    SubsequenceChecker2(const string& t) {
        int n = t.size();
        nxt.resize(n + 1);
        nxt[n].fill(n);  // 越界哨兵: 之后任何位置都找不到
        for(int i = n - 1; i >= 0; i--) {
            nxt[i] = nxt[i + 1];
            nxt[i][t[i] - 'a'] = i;
        }
    }

    bool isSubsequence(const string& s) {
        int cur = 0;
        for(char c : s) {
            int p = nxt[cur][c - 'a'];
            if(p == (int)nxt.size() - 1) return false;  // 到达哨兵, 匹配失败
            cur = p + 1;
        }
        return true;
    }
};