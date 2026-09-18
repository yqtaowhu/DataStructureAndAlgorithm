/*
 * @lc app=leetcode.cn id=871 lang=cpp
 *
 * [871] 最低加油次数
 */

// @lc code=start
class Solution {
public:
    // 堆贪心：一路向前开，把途经的加油站油量存入大顶堆。
    // 一旦当前油量到不了下一个站点，就从「已路过的油站」里取油量最大的那个加油一次。
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        priority_queue<long> pq; // 大顶堆：路过但未加油的油站油量
        long fuel = startFuel;
        int stops = 0, n = stations.size();
        for (int i = 0; i <= n; i++) {
            // 当前目标点（终点或下一站）的距离
            long curPos = (i == n) ? target : stations[i][0];
            // 油量不够开到 curPos，就不断从堆里补油
            while (fuel < curPos) {
                if (pq.empty()) return -1; // 无油可加，失败
                fuel += pq.top(); pq.pop();
                stops++;
            }
            if (i < n) pq.push(stations[i][1]); // 到达该站，把油量存入堆
        }
        return stops;
    }
};
// @lc code=end
