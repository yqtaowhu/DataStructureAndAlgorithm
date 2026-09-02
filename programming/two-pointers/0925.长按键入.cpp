// [925] 长按键入
// 双序列同向指针：i 走 name，j 走 typed，typed 不能出现 name 中没有的新字符
class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int i = 0, j = 0, m = name.size(), n = typed.size();
        while (j < n) {
            if (i < m && name[i] == typed[j]) {
                i++, j++;               // 匹配成功，双指针各进一格
            } else if (j > 0 && typed[j] == typed[j - 1]) {
                j++;                    // 长按键入：与前一字符相同，跳过
            } else {
                return false;           // 出现了 name 中没有的新字符
            }
        }
        return i == m;                  // name 必须被完整消耗
    }
};
