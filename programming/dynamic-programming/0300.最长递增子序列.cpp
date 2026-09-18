class Solution {
public:
    // 更简洁的写法
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> g;
        for(int i=0; i<n; i++) {
            auto it = lower_bound(g.begin(), g.end(), nums[i]);
            if(it == g.end()) { // 没有找到>=nums[i]的元素，则插入到末尾
                g.push_back(nums[i]);
            } else {
                *it = nums[i];
            }
        }
        return g.size();
    }
    // int lengthOfLIS(vector<int>& nums) {
    //     if(nums.empty()) return 0;
    //     int n = nums.size();
    //     vector<int> v;
    //     v.push_back(nums[0]);
    //     for(int i=1; i<n; i++) {
    //         if(nums[i] > v.back()) {
    //             v.push_back(nums[i]);
    //         } else {
    //             auto it = lower_bound(v.begin(), v.end(), nums[i]);
    //             //int pos = lower_bound(v.begin(), v.end(), nums[i]) - v.begin();
    //             *it = nums[i];
    //         }

    //     }
    //     return v.size();
    // }
};