/*
 * @lc app=leetcode.cn id=116 lang=cpp
 *
 * [116] 填充每个节点的下一个右侧节点指针
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/
class Solution {
public:
    // o(1)方法
    Node* connect(Node* root) {
        if(!root) return root;
        Node *pre = root;
        Node *cur = NULL;
        while(pre->left) {
            cur = pre;
            while(cur) {
                cur->left->next = cur->right;
                if(cur->next) cur->right->next = cur->next->left;
                cur = cur->next;
            }
            pre = pre->left;
        }
        return root;
    }
    // 层序遍历
    Node* connect_1(Node* root) {
        if(!root) return root;
        queue<Node*> que;
        que.push(root);

        while(!que.empty()) {
            int size = que.size();
            // 头节点
            Node* pre = nullptr;
   
            for(int i=0; i< size; i++) {
                Node* cur = que.front();
                que.pop();

                //很巧妙的解法，一定注意了
                if(i>0) {
                    pre->next = cur;
                }
                pre = cur;

                if(cur->left) {
                    que.push(cur->left);
                }
                if(cur->right) {
                    que.push(cur->right);
                }
            }
        }
        return root;
    }
};
// @lc code=end

