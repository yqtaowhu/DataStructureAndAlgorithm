# 二分查找 C++ 模板（简单易记版）

## 核心思想：红蓝染色法

把数组看成待染色的序列：
- **红色**：不满足条件的左边部分（`< target`）
- **蓝色**：满足条件的右边部分（`>= target`）

二分就是在找**红蓝的分界线**。整个模板只需要背一个骨架，改一个比较符号即可。

## 万能模板（左闭右开 `[left, right)`）

```cpp
// 返回最小的满足 nums[i] >= target 的下标 i
// 如果不存在，返回 nums.size()（可以把想象中的 nums[n] 当作正无穷）
int lower_bound(vector<int>& nums, int target) {
    int left = 0, right = nums.size();   // 左闭右开区间
    while (left < right) {               // 区间不为空就继续
        int mid = left + (right - left) / 2;
        if (nums[mid] >= target) {
            right = mid;    // mid 可能是答案，不能丢
        } else {
            left = mid + 1; // mid 一定不是答案，排除
        }
    }
    return left;            // 循环结束 left == right，即为分界点
}
```

**只需记住三句话：**
1. 循环条件 `left < right`
2. 满足条件 → `right = mid`（mid 可能是答案）
3. 不满足 → `left = mid + 1`（mid 一定不是答案）

## 改一个符号，解决四类问题

```cpp
// 1. 第一个 >= target 的位置        → nums[mid] >= target （lower_bound）
// 2. 第一个 >  target 的位置        → nums[mid] >  target （upper_bound）
// 3. 第一个 == target 的位置        → lower_bound(nums, target)
//    （再判断 left < n && nums[left] == target）
// 4. 最后一个 == target 的位置      → upper_bound(nums, target) - 1
//    （再判断 left > 0 && nums[left-1] == target）

// 完整示例：34. 在排序数组中查找元素的第一个和最后一个位置
vector<int> searchRange(vector<int>& nums, int target) {
    int start = lower_bound(nums, target);
    if (start == nums.size() || nums[start] != target)
        return {-1, -1};
    int end = lower_bound(nums, target + 1) - 1; // >target 的前一个
    return {start, end};
}
```

## 模板的推广：二分答案

只要问题能转化为「**找一个边界：满足条件的最小值/最大值**」，就能套同一个模板。
关键：`nums[mid]` 换成 `check(mid)`，从"问数组元素"变成"问一个函数"。

```cpp
// 满足 check 的最小 x（check(x) 越大越容易满足）
int minAnswer(int lo, int hi) {
    int left = lo, right = hi + 1;   // 右边界 +1，答案可能取到 hi
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (check(mid)) right = mid;
        else left = mid + 1;
    }
    return left;
}
```

> 求最大值技巧：转化为「最小的满足 `!check` 的位置减一」，或者用 `mid = left + (right - left + 1) / 2` 配合 `left = mid`。

## 用这个模板能解决的 LeetCode 题目（全收录）

> 链接指向本仓库已有题解；无链接的题目可直接套上方模板。

### 一、直接套 lower_bound：在有序数组上找边界

| 题目 | 要点 |
|------|------|
| [35. 搜索插入位置](0035.搜索插入位置.cpp) | 就是 lower_bound 本身 |
| [34. 在排序数组中查找元素的第一个和最后一个位置](0034.在排序数组中查找元素的第一个和最后一个位置.cpp) | lower_bound 两次（target 和 target+1） |
| 704. 二分查找 | 最基础版，找 == target |
| 744. 寻找比目标字母大的最小字母 | upper_bound，注意回环取第一个字符 |
| 278. 第一个错误的版本 | lower_bound 的经典应用场景 |
| 374. 猜数字大小 | check(mid) 就是 guess 接口 |
| 275. H 指数 II | lower_bound 找 citations[i] >= n-i 的边界 |
| [74. 搜索二维矩阵](0074.搜索二维矩阵.cpp) | 把二维下标展开成一维二分 |
| [240. 搜索二维矩阵 II](../array/240.搜索二维矩阵2.cpp) | 逐行二分，或右上角起步二叉下降 |
| 2300. 咒语和药水的成功对数 | 对 potions 排序后套 lower_bound |
| 2563. 统计公平数对的数目 | 两次 lower_bound 数对子数 |
| 2389. 和有限的最长子序列 | 排序 + 前缀和 + lower_bound（[已有题解](../data-structure/2389.和有限的最长子序列.cpp)） |
| 349/350. 两个数组的交集 | 排序后二分，或直接双指针 |
| 540. 有序数组中的单一元素 | 偶数下标比较，二分找分界 |
| 1539. 第 k 个缺失的正整数 | 找第一个 nums[i] - i - 1 >= k 的边界 |
| 1608. 特殊数组的特征值 | 枚举 + lower_bound 计数 |
| 1287. 有序数组中出现次数超过25%的元素 | upper_bound - lower_bound 检查 |

### 二、变形边界：单峰 / 旋转 / 特殊结构

| 题目 | 要点 |
|------|------|
| [33. 搜索旋转排序数组](0033.搜索旋转排序数组.cpp) | 先判断哪半边有序 |
| [81. 搜索旋转排序数组 II](0081.搜索旋转排序数组-ii.cpp) | 33 的去重版，`nums[mid]==nums[right]` 时 right-- |
| [153. 寻找旋转排序数组中的最小值](153.寻找旋转排序数组中的最小值.cpp) | `nums[mid] <= nums[right]` → 答案在左半 |
| [154. 寻找旋转排序数组中的最小值 II](154.寻找旋转排序数组中的最小值-ii.cpp) | 153 的去重版 |
| [162. 寻找峰值](162.寻找峰值.cpp) | `nums[mid] > nums[mid+1]` → 峰在左半 |
| 852. 山脉数组的峰顶索引 | 162 的简化版 |
| 1095. 山脉数组中查找目标值 | 三次二分：先找峰顶，再在两侧找 |
| [167. 两数之和 II - 输入有序数组](../array/167.两数之和-ii-输入有序数组.cpp) | 枚举一个数，另一个用 lower_bound |

### 三、二分答案：最小化最大值 / 最大化最小值

check(x) 单调即可套模板，「最小值最大化」取反 check 即可。

| 题目 | 要点 |
|------|------|
| 875. 爱吃香蕉的珂珂 | 二分速度 k，check = 能否 h 小时吃完 |
| 1011. 在 D 天内送达包裹的能力 | 二分运力，check = 能否 D 天运完 |
| 410. 分割数组的最大值 | 二分最大和，check = 能否分成 m 段 |
| 1482. 制作花束 | 二分天数，check = 能否做成 m 束 |
| 1283. 使结果不超过阈值的最小除数 | 二分除数，check = 除完总和 <= threshold |
| 1802. 有界数组中指定下标处的最大值 | 二分峰值，check = 总和 <= maxSum |
| 1870. 准时到达的列车最小时速 | 二分时速（浮点版） |
| 2064. 分配给商店的最多商品的最小值 | 「最小化最大值」经典题 |
| 2226. 每个小孩最多能分到多少糖果 | 「最大化最小值」经典题 |
| 2594. 修车的最少时间 | 二分时间，check = 能修完 cars 辆 |
| 2560. 打家劫舍 IV | 二分窃取价值 + 贪心 check |
| 1760. 袋子里最少数目的球 | 二分最大球数 |
| 441. 排列硬币 | 二分行数 |
| 1201. 丑数 III | 二分答案 + 容斥计数 |
| 793. 阶乘函数后 K 个零 | 二分 n，check = 尾零数 |
| [69. x 的平方根](../math/0069.x-的平方根.cpp) | 二分答案，check = 平方 <= x |
| 367. 有效的完全平方数 | 69 的变体 |
| 1891. 割绳子（会员题） | 同 410 思路 |

### 四、二分 + 计数：第 k 小 / 比较中位数

二分值域，用计数函数作为 check。

| 题目 | 要点 |
|------|------|
| [4. 寻找两个正序数组的中位数](0004.寻找两个有序数组的中位数.cpp) | 在较短的数组上二分分割点 |
| 378. 有序矩阵中第 K 小的元素 | 二分值域，check = 矩阵中 <= x 的个数 |
| 668. 乘法表中第 k 小的数 | 378 的变体 |
| 719. 找出第 k 小的距离对 | 二分距离，排序后双指针计数 |
| 2040. 两个有序数组的第 K 小乘积 | 二分乘积值，计数负零正三段 |
| 287. 寻找重复数 | 二分值域 + 计数（也可用快慢指针） |
| 611. 有效三角形的个数 | 排序后枚举一边 + 二分找边界 |
| [300. 最长递增子序列](../dynamic-programming/300.cpp) | 贪心 + lower_bound 维护 tails 数组 |
| 354. 俄罗斯套娃信封问题 | 宽度降序宽度升序后 LIS |
| 1964. 通过连接另一个数组的子序列最大 LIS（LIS 变体） | [已有题解](../dynamic-programming/1964.cpp) |

### 五、其他：面试常见变体

| 题目 | 要点 |
|------|------|
| 面试题 10.05. 稀疏数组搜索 | 含空串的二分 |
| 363. 矩形区域不超过 K 的最大数值和 | 前缀和 + 有序集合二分 |
| 710. 黑名单中的随机数 | 黑名单映射（思路涉及二分计数） |
| 剑指 Offer 53 - II. 0～n-1 中缺失的数字 | 直接套 lower_bound |
| LCR 173. 点名 | 同上 |

## 记忆口诀

> **左闭右开 `left < right`，满足往左收 `right = mid`，不满足往右排 `left = mid + 1`，循环结束 `left` 就是分界线。**

改成找 `> target`：把 `>=` 改成 `>`；
找最后一个：套 `upper_bound` 再减一；
二分答案：把 `nums[mid]` 换成 `check(mid)`。
