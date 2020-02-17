/*
 * @lc app=leetcode.cn id=138 lang=cpp
 *
 * [138] 复制带随机指针的链表
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

// 方法1: 首先应该想到用hash表存储起来，然后连接next和random指针即可
class Solution {
public:
    Node* copyRandomList(Node* head) {
        // key : 原始节点， value: 复制节点
        unordered_map<Node*, Node*> hash;
        Node* cur = head;
        // 存储hash表中
        while(cur) {
            Node* copy = new Node(cur->val); // 创建新的节点，并赋值
            hash[cur] = copy;
            cur = cur->next;
        }
        cur = head;
        // 连接指针
        while(cur) {
            hash[cur]->next = hash[cur->next];
            hash[cur]->random = hash[cur->random];
            cur = cur->next;
        }
        return hash[head];
    }
};

//方法2: 三步走
//复制节点，同时将复制节点链接到原节点后面，如A->B->C 变为 A->A'->B->B'->C->C'。
//设置节点random值。
//将复制链表从原链表分离。

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) {
            return head;
        }
        Node *node = head;
        //1. 将复制节点添加到原节点后面
        while (node != nullptr) {
            Node *copy = new Node(node->val, nullptr, nullptr);
            copy->next = node->next;
            node->next = copy;
            node = copy->next;
        }
        
        //2. 复制random节点
        node = head;
        while (node != nullptr) {
            if (node->random != nullptr) {
                node->next->random = node->random->next;
            }            
            node = node->next->next;
        }
        
        //3. 分离链表
        node = head;
        Node *newHead = head->next;
        Node *newNode = newHead;
        while (node != nullptr) {
            node->next = node->next->next;     
            if (newNode->next != nullptr) {
                newNode->next = newNode->next->next;            
            }            
            node = node->next;
            newNode = newNode->next;
        }
        return newHead;
    }
};
// @lc code=end

