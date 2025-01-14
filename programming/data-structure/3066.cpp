class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int res = 0;
        if(nums.size() < 2) {
            return res;
        }
        priority_queue<long long int, vector<long long int>, greater<long long int>> pq;
        for(auto &num : nums) {
            pq.push(num);
        }
        while(pq.size() >= 2) {
            int x = pq.top();
            pq.pop();
            int y = pq.top();
            pq.pop();
            if (x >= k) {
                break;
            } 
            res++;
            // 2x + y >= k
            if ((k - y) / 2 <= x) {
                pq.push(k+1);
            }
            pq.push(x * 2LL + y);
        }
        return res;
    }
};