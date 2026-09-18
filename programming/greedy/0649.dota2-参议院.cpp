/*
 * @lc app=leetcode.cn id=649 lang=cpp
 *
 * [649] Dota2 参议院
 */

// @lc code=start
class Solution {
public:
    // 队列贪心：双方各按出现顺序入队，每轮取两队队首比较下标，
    // 下标小者（更靠前）先行使权利，ban 掉对方队首，自己存活到下一轮（下标 +n）。
    string predictPartyVictory(string senate) {
        int n = senate.size();
        queue<int> radiant, dire;
        for (int i = 0; i < n; i++) {
            if (senate[i] == 'R') radiant.push(i);
            else dire.push(i);
        }
        while (!radiant.empty() && !dire.empty()) {
            int r = radiant.front(), d = dire.front();
            radiant.pop(); dire.pop();
            if (r < d) radiant.push(r + n); // R 更靠前，ban 掉 D，自己进入下一轮
            else dire.push(d + n);          // D 更靠前，ban 掉 R
        }
        return radiant.empty() ? "Dire" : "Radiant";
    }
};
// @lc code=end
