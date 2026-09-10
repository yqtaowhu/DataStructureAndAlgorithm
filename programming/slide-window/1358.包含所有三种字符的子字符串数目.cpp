// 1358. 包含所有三种字符的子字符串数目
// 模板：不定长窗口 · 计数型（与 713 方向相反）
// 713 是"窗口越短越不合法"⇒ 每轮 += right-left+1；
// 本题是"窗口越长越合法"⇒ 收缩到刚好不合法后，起点取 0..left-1 都合法，每轮 += left
// 同族：76 最小覆盖子串、3697/3698 合法子字符串计数

class Solution {
public:
    int numberOfSubstrings(string s) {
        int cnt[3] = {0};
        int left = 0, ans = 0;
        for (int right = 0; right < (int)s.size(); right++) {
            cnt[s[right] - 'a']++;                        // 入
            while (cnt[0] && cnt[1] && cnt[2]) {          // 出：三种都齐了还能再缩
                cnt[s[left++] - 'a']--;
            }
            ans += left;                                  // 更新：起点可取 0..left-1
        }
        return ans;
    }
};
