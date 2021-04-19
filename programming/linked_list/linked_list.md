- [链表相关算法练习题](#链表相关算法练习题)
  - [1. 链表倒数第k个节点](#1-链表倒数第k个节点)
  - [2.回文链表相关题目](#2回文链表相关题目)
    - [2.1 判断一个链表是不是回文](#21-判断一个链表是不是回文)
  

# 链表相关算法练习题

## [1. 链表倒数第k个节点](https://leetcode-cn.com/problems/lian-biao-zhong-dao-shu-di-kge-jie-dian-lcof/)
很明显的快慢指针题目
```
class Solution {
public:
    ListNode* getKthFromEnd(ListNode* head, int k) {
        ListNode* slow = head, *fast = head;
        for(int i=0; i < k && fast; i++) {
            fast = fast->next;
        }
        //cout << fast->val << endl;
        while(fast) {
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
};
```

## 2.回文链表相关题目
### 2.1 判断一个链表是不是回文
a. 找到中点
b. 反转后半部分链表
c. 判断是不是回文

```
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(!head || !head->next) {
            return true;
        }
        // 1->2->2->1      ->  1->2->2<-1
        // 1->2->3->2->1   ->  1->2->3<-2<-1
        ListNode* slow = head, *fast = head;
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        // 反转链表
        ListNode* cur = slow->next, *pre = slow;
        slow->next = nullptr;
        while(cur) {
            ListNode* nxt = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nxt;
        }
        ListNode* tail = pre;
        cur = head;
        while(cur && tail) {
            if(cur->val != tail->val) {
                return false;
            }
            cur = cur->next;
            tail = tail->next;
        }
        return true;
    }
};
```