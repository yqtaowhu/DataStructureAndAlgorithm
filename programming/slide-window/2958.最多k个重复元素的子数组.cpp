
// 标准模板题
// 维护窗口，直到满足条件的窗口
class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int size = nums.size(), res = 0;
        unordered_map<int, int> map;
        for(int i=0, j=0; j < size; j++) {
            map[nums[j]]++;
            // 窗口不符合条件
            while(map[nums[j]] > k) {
                map[nums[i++]]--;
            }
            res = max(res, j-i+1);
        }
        return res;
    }
};