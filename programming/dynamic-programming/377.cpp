class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        // 使用 unsigned 可以让溢出不报错
        // 对于溢出的数据，不会影响答案的正确性（题目保证）
        vector<unsigned> f(target + 1);
        f[0] = 1;
        for (int i = 1; i <= target; i++) {
            for (int x : nums) {
                if (x <= i) {
                    f[i] += f[i - x];
                }
            }
        }
        return f[target];
    }
};