// [345] 反转字符串中的元音字母
// 模板一：对撞指针，两端各跳过辅音，元音才交换
class Solution {
public:
    bool isVowel(char c) {
        c = tolower(c);
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
    string reverseVowels(string s) {
        int left = 0, right = s.size() - 1;
        while (left < right) {
            if (!isVowel(s[left]))      left++;   // 左边不是元音，右移淘汰
            else if (!isVowel(s[right])) right--; // 右边不是元音，左移淘汰
            else swap(s[left++], s[right--]);    // 两端都是元音，交换
        }
        return s;
    }
};
