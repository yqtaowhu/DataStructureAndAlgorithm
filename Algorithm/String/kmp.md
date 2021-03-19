# KMP 算法

问题: 给定一个字符串S和一个模式串P，在S字符串中找出P字符串出现的第一个位置 (从0开始)。如果不存在，则返回  -1。

## 基础算法

一个比较简单的做法，就是使用S字符串的每个字符开头和P字符串进行匹配。

```
class Solution {
public:
    int strStr(string haystack, string needle) {
        int m = haystack.size(), n = needle.size();
        int i = 0, j = 0;
        for(i=0; i <= m -n; i++) {
            for(j=0; j<n; j++) {
                if(haystack[i+j] != needle[j]) {
                    break;
                }
            }
            if(j == n) return i;
        }
        return -1;
    }
};
```

上述的代码中，每次匹配失败，则会将S的指针向前移动一位，尽管可能匹配上了很多了，还是要将i的z指针回溯。
```
匹配到D时失败
S : ABCDAB ABCDABCDABDE”
P : ABCDABD

回溯重新进行匹配，S[1]!=P[0]，如何保持S的指针不变，P的指针移动呢？
S : ABCDAB ABCDABCDABDE”
P :  ABCDABD

移动到此处 j = next[j]
S : ABCDAB ABCDABCDABDE”
P :     ABCDABD
```

## 最大前缀后缀

```
字符        A  B  C  D  A   B  D
最大前缀后缀 0  0  0  0  1   2  0

所以当D匹配失败后，D前面B最大前缀后缀为2， 前面已经匹配了6个字符了，所以模式串要移动6-2=4位，如下所示：
S : ABCDAB ABCDABCDABDE”
P :     ABCDABD

此时C没有匹配，已经匹配了2位，所以要移动 2-0 = 2

S : ABCDAB ABCDABCDABDE”
P :       ABCDABD
...
```

求解最大前缀后缀：

```
// 索引从1开始
P       "" A  B  C  D  A   B  D
next    0  0  0  0  0  1   2  0 
for (int i = 2, j = 0; i <= n; i ++ ) {
    while (j && p[i] != p[j + 1]) j = ne[j]; // 如果不相等j往后退
    if (p[i] == p[j + 1]) j ++ ;
    ne[i] = j;
}
```

进行匹配

```
// 从索引1开始 i=1，j=0,所以匹配的是s[i]和p[j+1].可以看到这个模板在计算next和匹配时基本一致，一定要记住
S : ''ABCDAB ABCDABCDABDE”
P : ''ABCDABD

for (int i = 1, j = 0; i <= m; i ++ ) {
    while (j && s[i] != p[j + 1]) j = ne[j];
    if (s[i] == p[j + 1]) j ++ ;
    if (j == n) {
        printf("%d ", i - n);
        j = ne[j];
    }
}
```



