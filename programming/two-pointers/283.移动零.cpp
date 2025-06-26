// 简单题
// 两种做法，一种是交换，一种是赋值，下面是交换的做法
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int size = nums.size();
        if(size == 0) return;
        int left = 0, right = 0;
        while(right < size) {
            if(nums[right]) {
                swap(nums[right], nums[left]);
                left++;
            }
            right++;
        }
    }
};