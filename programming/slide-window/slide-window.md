# 滑动窗口相关算法练习题

```
// 滑动窗口的通用代码
int left = 0, right = 0;

while (right < s.size()) {
    window.add(s[right]);
    right++;
    
    while (valid) {
        window.remove(s[left]);
        left++;
    }
}

```
| Title | Solution | Source|
| ---- | -------|------|
|无重复字符串最长子串|[3.无重复字符串最长子串](3.无重复字符的最长子串.cpp)||
|最小覆盖子串|[76.最小覆盖子串](76.最小覆盖子串.cpp)|
|滑动窗口|[239.滑动窗口](../data-structure/239.滑动窗口最大值.cpp)|
|438. 找到字符串中所有字母异位词|[438. 找到字符串中所有字母异位词](438.找到字符串中所有字母异位词.cpp)|

