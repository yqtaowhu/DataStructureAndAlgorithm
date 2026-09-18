// 1171. 从链表中删去总和值为零的连续节点
// https://leetcode.cn/problems/remove-zero-sum-consecutive-nodes-from-linked-list/
//
// 【前缀和 + 哈希表 · 模式三：链表上的前缀和】
// 见模板文档：./前缀和哈希表模板.md
//
// 题意：反复删除链表中「和为 0 的连续节点」，直到不存在为止，返回最终链表头。
//
// 关键转化：与数组完全一样，一段连续节点和为 0 <=> 这段首尾的前缀和相等。
// 技巧：用哈希表记录每个前缀和「最后一次」出现的节点（同一 key 反复覆盖）。
//   第一趟：从头扫，记录每个前缀和对应的最后节点；
//   第二趟：再从头扫，对每个节点 cur（前缀和 s），令 cur->next = last[s]->next，
//          直接跳过「与 cur 前缀和相同」的那一整段（其和为 0）。
// 两趟都从哑结点 dummy(0) 开始，天然覆盖「开头就是零和段」的情况。
//
// 为什么存「最后」而不是「首次」：存最后位置能让每个节点一步跳到最远的可续接点，
// 一次性消掉所有嵌套/相邻的零和段，无需真的反复删除。

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode dummy(0);
        dummy.next = head;
        unordered_map<int, ListNode*> last; // 前缀和 -> 最后一次出现的节点

        ListNode* p = &dummy;
        int s = 0;
        while (p) {                 // 第一趟：记录每个前缀和的最后节点
            s += p->val;
            last[s] = p;            // 后写覆盖前写 => 存的是最后位置
            p = p->next;
        }

        p = &dummy;
        s = 0;
        while (p) {                 // 第二趟：跳过零和段
            s += p->val;
            p->next = last[s]->next; // 相同前缀和的最后节点，其后继即答案续接点
            p = p->next;
        }
        return dummy.next;
    }
};
