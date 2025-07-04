class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // 不是优先队列，优先队列会改变顺序，单调递减的队列，则头就是最大的值
        // 使用deque双端队列，而不是queue
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