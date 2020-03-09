# 二分算法相关题目

```
// 查找左边界
int l = 0, r = n - 1;
while (l < r) {
    int mid = l + r >> 1;
    if (q[mid] >= x) r = mid;
    else l = mid + 1;
}

// 查找右边界
int l = 0, r = n - 1;
while (l < r) {
    int mid = l + r + 1 >> 1;
    if (q[mid] <= x) l = mid;
    else r = mid - 1;
}
```

