// [876] 链表的中间结点
// 模板三：快慢指针，快指针一次两步，慢指针一次一步
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode *slow = head, *fast = head;
        while (fast && fast->next) {
            slow = slow->next;          // 循环结束：奇数个节点 slow 是中点
            fast = fast->next->next;    // 偶数个节点 slow 是右中点
        }
        return slow;
    }
};
