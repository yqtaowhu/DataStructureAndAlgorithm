// [977] 有序数组的平方
// 模板一：对撞指针。原数组两端是平方后最大的候选，从结果末尾往前填
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n);
        int left = 0, right = n - 1, pos = n - 1; // pos：结果下一个写入位置
        while (left <= right) {
            long ls = (long)nums[left] * nums[left];
            long rs = (long)nums[right] * nums[right];
            if (ls > rs) {          // 左端平方更大，填到 pos
                res[pos--] = ls;
                left++;
            } else {
                res[pos--] = rs;
                right--;
            }
        }
        return res;
    }
};
