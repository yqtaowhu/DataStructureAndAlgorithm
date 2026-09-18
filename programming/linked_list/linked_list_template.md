# 链表 C++ 模板（简单易记版）

## 核心思想：指针操作 + 虚拟头节点

链表题的两大保命技巧：
1. **虚拟头节点 dummy**：头节点可能被删/被换时，`dummy->next = head`，最后返回 `dummy->next`——从此不用单独处理头节点
2. **画图再动手**：每一步改变量前画箭头图，确认"先连后断"的顺序，避免丢链

链表操作没有算法难度，只有**指针赋值顺序**的难度。

## 万能模板一：反转链表（迭代三指针）

```cpp
// 示例：206. 反转链表
ListNode* reverseList(ListNode* head) {
    ListNode* prev = nullptr;
    ListNode* cur = head;
    while (cur) {
        ListNode* next = cur->next;   // 1. 先存下家
        cur->next = prev;             // 2. 掉头
        prev = cur;                   // 3. prev 前进
        cur = next;                   // 4. cur 前进
    }
    return prev;                      // cur 为空时，prev 即新头
}
```

**只需记住三句话：**
1. `prev` 是已反转部分的头，`cur` 是待处理节点
2. 循环体内固定顺序：**存 next → 掉头 → 双双前进**
3. 返回 `prev`

> 反转区间 [m, n]（92 反转链表 II）：先走到 m 前一个节点，再对区间内做同样的三指针反转。
> k 个一组（25）：数够 k 个，先断后反转再拼接。

## 万能模板二：快慢指针（中点 / 判环 / 倒数第 n）

```cpp
// 876. 找中点
ListNode *slow = head, *fast = head;
while (fast && fast->next) { slow = slow->next; fast = fast->next->next; }
// slow 停在中点（偶数个时是右中点）；148 排序链表用它找中点后断开归并

// 141. 判环
while (fast && fast->next) {
    slow = slow->next; fast = fast->next->next;
    if (slow == fast) return true;      // 相遇 = 有环
}
return false;

// 19. 删除倒数第 n 个：fast 先走 n 步，再双指针同步走到尾
//    （配 dummy 使用，slow 停在待删节点的前一个）
```

> 142. 找环入口：相遇后一个指针回 head，两指针同速走，再相遇即入口。

## 万能模板三：dummy 头节点 + 删除/合并

```cpp
// 示例：203. 移除链表元素 / 83. 删除重复元素 —— 通用删除骨架
ListNode* removeElements(ListNode* head, int val) {
    ListNode dummy(0, head);
    ListNode* cur = &dummy;
    while (cur->next) {
        if (cur->next->val == val) {
            ListNode* del = cur->next;
            cur->next = del->next;      // 跨过待删节点
            delete del;                 // 单独判删，不要边走边删
        } else {
            cur = cur->next;            // 只有不删时才前进！
        }
    }
    return dummy.next;
}
```

**要点：** 删除节点时**当前指针停在待删节点的前一个**；只有"没删"时才 `cur = cur->next`，否则会跳过连续待删节点。

## 万能模板四：合并有序链表

```cpp
// 示例：21. 合并两个有序链表（23 合并 K 个 = 两两合并 or 小顶堆）
ListNode* mergeTwoLists(ListNode* a, ListNode* b) {
    ListNode dummy; ListNode* tail = &dummy;
    while (a && b) {
        if (a->val <= b->val) { tail->next = a; a = a->next; }
        else                  { tail->next = b; b = b->next; }
        tail = tail->next;
    }
    tail->next = a ? a : b;             // 剩下的直接接上
    return dummy.next;
}
```

## 改一处，解决一类问题

| 问题 | 改哪里 |
|------|--------|
| 两数相加（2） | 逐位相加 + carry，注意最后进位 |
| 24 两两交换 | dummy + 每次交换一对，指针图画清楚 |
| 61 旋转链表 | 成环再断：找到倒数第 k+1 个，`newHead = 其->next` |
| 143 重排链表 | 找中点 → 反转后半 → 交替合并三步走 |
| 234 回文链表 | 找中点 + 反转后半 + 逐个比较 |
| 160 相交链表 | 双指针走完换道，消除长度差 |
| 148 排序链表 | 快慢找中点断开 + 归并 |
| 82 删除重复元素 II | dummy + 全部重复的一跳到底 |

## 用这个模板能解决的 LeetCode 题目（本目录收录）

> 链接指向本仓库已有题解；无链接的题目可直接套上方模板。

### 一、反转类

| 题目 | 要点 |
|------|------|
| [206. 反转链表](206.反转链表.cpp) | 三指针标准模板 |
| [92. 反转链表 II](92.反转链表-ii.cpp) | 反转指定区间 |
| [25. K 个一组翻转](25.k-个一组翻转链表.cpp) | 分组反转 + 拼接 |
| [24. 两两交换](24.两两交换链表中的节点.cpp) | dummy + 成对交换 |

### 二、快慢指针类

| 题目 | 要点 |
|------|------|
| [141. 环形链表](141.环形链表.cpp) | 相遇判环 |
| [142. 环形链表 II](142.环形链表-ii.cpp) | 相遇后回 head |
| [876. 链表的中间结点](../876.链表的中间结点.cpp) | 快慢找中点 |
| [19. 删除倒数第 n 个](0019.删除链表的倒数第n个节点.cpp) | 快先走 n 步 |

### 三、删除与合并类

| 题目 | 要点 |
|------|------|
| [203. 移除链表元素](203.移除链表元素.cpp) | dummy 删除骨架 |
| [83. 删除重复元素](83.删除排序链表中的重复元素.cpp) | 留一个 |
| [82. 删除重复元素 II](82.删除排序链表中的重复元素-ii.cpp) | 全删干净 |
| [21. 合并两个有序链表](0021.合并两个有序链表.cpp) | dummy + tail |
| [23. 合并 K 个链表](0023.合并k个排序链表.cpp) | 分治合并或小顶堆 |

### 四、综合操作

| 题目 | 要点 |
|------|------|
| [143. 重排链表](143.重排链表.cpp) | 中点+反转+合并 |
| [234. 回文链表](234.回文链表.cpp) | 中点+反转+比较 |
| [148. 排序链表](148.排序链表.cpp) | 归并排序 |
| [160. 相交链表](160.相交链表.cpp) | 双指针换道 |
| [2. 两数相加](0002.两数相加.cpp) | carry 进位 |
| [86. 分隔链表](86.分隔链表.cpp) | 两条链再拼接 |

## 记忆口诀

> **头部风险 dummy 保；反转四步存转进；删除停在删之前；快慢一步对两步。**
> 动指针前先画图，改链接的顺序永远是"先连新、再断旧"。

