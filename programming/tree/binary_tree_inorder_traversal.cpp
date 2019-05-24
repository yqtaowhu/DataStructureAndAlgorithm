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
vector<int> inorderTraversalRecursion(TreeNode* root) {
    // 左-> 根 -> 右的遍历次序
    if (root != nullptr) {
        if (root->left)
            inorderTraversalRecursion(root->left);

        res.push_back(root->val);    

        if (root->right)
            inorderTraversalRecursion(root->right);
    }
    return res;
}

vector<int> inorderTraversalIteration(TreeNode* root) {
    /*
     * 借助栈，中序遍历   左-> 根 -> 右,所以一直遍历左孩子，同时压栈 
     */
    vector<int> res;
    stack<TreeNode*> st;
    while (root || !st.empty()) {
        while (root) { //一直遍历左孩子
            st.push(root);
            root = root->left;
        }
        // root为空，弹出栈
        root = st.top();
        st.pop();
        res.push_back(root->val);
        root = root->right;
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
    vector<int> res = inorderTraversalRecursion(p1);
    cout << "递归前序遍历" << endl;
    for (auto &v:res) {
        cout << v << " ";
    }
    cout << endl;

    res.clear();
    // 迭代前序遍历
    res = inorderTraversalIteration(p1);
    cout << "迭代前序遍历" << endl;
    for (auto &v:res) {
        cout << v << " ";
    }
    cout << endl;

    return 0;
}
