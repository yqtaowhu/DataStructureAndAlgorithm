
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/
class Solution {
public:
    Node* treeToDoublyList(Node* root) {
        if(!root) return root;
       // 排序双向链表，因此使用中序遍历
       stack<Node*> st;
       Node* pre=nullptr, *head=root;
       while(root || !st.empty()) {
           if(root) {
               st.push(root);
               cout<<root->val<<endl;
               root = root->left;
           } else {
               root = st.top();
               st.pop();
               
               // 具体处理过程，其他的都是中序遍历的模板
               if(pre == nullptr) {
                   pre = root;
                   head = root;  // 此时是最小值
               } else {
                   // 更新节点
                   pre->right = root;
                   root->left = pre;
                   pre = root;
               }

               root = root->right;
           }
       }
       // 连接收尾元素
       pre->right = head;
       head->left = pre;
       return head; 
    }
};

class Solution2 {
public:
    // 中序遍历骨架：改「处理」部分即可适配不同 BST 中序题
    void inorder(Node* root, Node*& prev, Node*& head) {
        if (!root) return;
        inorder(root->left, prev, head);
        // ===== 处理当前节点：prev 串接 =====
        if (!prev) head = root;                  // 中序第一个节点 = 链表头
        else { prev->right = root; root->left = prev; }
        prev = root;
        // ========================
        inorder(root->right, prev, head);
    }

    Node* treeToDoublyList(Node* root) {
        if (!root) return nullptr;
        Node* prev = nullptr;
        Node* head = nullptr;
        inorder(root, prev, head);
        // 首尾相连成环
        head->left = prev;
        prev->right = head;
        return head;
    }
};