// [344] 反转字符串
// 模板一：对撞指针，两端交换后向中间靠拢
class Solution {
public:
    void reverseString(vector<char>& s) {
        int left = 0, right = s.size() - 1;
        while (left < right) {          // 相遇即停
            swap(s[left++], s[right--]); // 每次淘汰两个元素
        }
    }
};
