/*
 * @lc app=leetcode.cn id=239 lang=cpp
 *
 * [239] 滑动窗口最大值
 */

// @lc code=start
#include<vector>
#include<deque>

using namespace std;
class Solution {
public:
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        int len = nums.size();
        if(len < k) return res;
        deque<int> deq;
        for(int i=0; i< len; i++) {
            // 队尾，队头的索引差值大于K了
            if(!deq.empty() && i-k+1 > deq.front()) {
                deq.pop_front();
            }
            // 维护单调队列
            while(deq.size()>0 && nums[deq.back()] <= nums[i]) {
                deq.pop_back();
            }
            // 加入，保持单调队列
            deq.push_back(i); 
            
            // 队头元素为需要元素
            if(!deq.empty() && i-k+1 >= 0) {
                res.push_back(nums[deq.front()]);
            }
        }
        return res;
    }
};
// @lc code=end

