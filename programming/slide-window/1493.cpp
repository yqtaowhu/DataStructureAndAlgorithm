class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        // 问题等价于0最多出现1次的窗口最长
        int size = nums.size(), res = 0;
        int cnt0 = 0;
        for(int i=0, j=0; j < size; j++) {
            if (nums[j] == 0) {
                cnt0 += 1;
            } 
            // 窗口不符合条件
            while(cnt0 > 1) {
                if(nums[i++] == 0) {
                    cnt0--;
                }
            }
            res = max(res, j-i);  // 这里有细微的变化
        }
        return res;
        
    }
};