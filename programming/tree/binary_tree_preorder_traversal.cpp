#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 递归版本
vector<int> res;
vector<int> preorderTraversalRecursion(TreeNode* root) {
    // 根-> 左 -> 又的遍历次序
    if (root != nullptr) {
        res.push_back(root->val);    
        if (root->left)
            preorderTraversalRecursion(root->left);
        if (root->right)
            preorderTraversalRecursion(root->right);
    }
    return res;
}

vector<int> preorderTraversalIteration(TreeNode* root) {
    /*
     * 借助栈，前序 根左右因此在每一个节点，先压入右孩子，然后左孩子
     */
    vector<int> res;
    stack<TreeNode*> st;
    st.push(root);
    while (!st.empty()) {
        TreeNode* cur = st.top();
        res.push_back(cur->val);
        st.pop();
        if (cur->right) {
            st.push(cur->right);
        }
        if (cur->left) {
           st.push(cur->left); 
        }
    }
    return res;
}

int main() {
    /* 构造二叉树
     *        1
     *      /   \
     *     2     3
     *          /
     *         4
     */
    TreeNode* p1 = new TreeNode(1);
    TreeNode* p2 = new TreeNode(2);
    TreeNode* p3 = new TreeNode(3);
    TreeNode* p4 = new TreeNode(4);
    p1->left = p2;p1->right=p3;p3->left=p4;
    // 递归前序遍历
    vector<int> res = preorderTraversalRecursion(p1);
    cout << "递归前序遍历" << endl;
    for (auto &v:res) {
        cout << v << " ";
    }
    cout << endl;

    res.clear();
    // 迭代前序遍历
    res = preorderTraversalIteration(p1);
    cout << "迭代前序遍历" << endl;
    for (auto &v:res) {
        cout << v << " ";
    }
    cout << endl;

    return 0;
}
