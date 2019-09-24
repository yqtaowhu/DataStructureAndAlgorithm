/* 树的路径问题总结
*               1
*              / \
*             2   3
*                /
*               4
*Q1. 求根节点到指定节点的路径，例如4 ： 1 3 4
*Q2. 求所有根节点到叶子节点的路径: https://leetcode.com/problems/binary-tree-paths/
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <string>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


/************************************************************************************/
//递归,dfs遍历
bool searchNodeRecursion(TreeNode* cur, TreeNode* dest, vector<TreeNode*> &path) {
    //边界处理
    if (cur == nullptr)
        return false;
    if (cur == dest) {
        path.push_back(cur);
        return true;
    }
    //搜索
    if (searchNodeRecursion(cur->left, dest, path) || searchNodeRecursion(cur->right, dest, path)) {
        path.push_back(cur);
        return true;
    }
    return false;
}

stack<TreeNode*> searchNodeIteration(TreeNode* root, TreeNode* dest) {
    /*
     * 借助栈，同中序遍历一样，但是稍微复杂
     * 1. 一直向左遍历左孩子,若找到，则返回
     * 2. 左孩子为空，不同于中序遍历，此时遍历右孩子,右孩子为空或者右孩子被遍历过了，则弹出栈
     * 3. 右孩子不空，则继续遍历其做孩子
     */
    vector<int> res;
    stack<TreeNode*> st;
    TreeNode* pre = nullptr; //标记前一个被弹出栈的元素
    while (root || !st.empty()) {
        while (root) {
           st.push(root); 
           if (root == dest) {
              return st; 
           }
           root = root->left;
        }
        //左孩子为空，遍历右孩子
        if (!st.empty()) {
            root = st.top();
            while (root->right == nullptr || (pre && root->right == pre)) {
                pre = st.top();
                st.pop();
                root = st.top();
            }
            root = root->right;
        }
    }
    return st;
}


/************************************************************************************
 *Q2. 求所有根节点到叶子节点的路径: https://leetcode.com/problems/binary-tree-paths/
 ***********************************************************************************/


void dfs(TreeNode* root, string path, vector<string> &res) {
    if (root->left == nullptr && root->right == nullptr) {
       res.push_back(path); 
    }
    if (root->left != NULL)
        dfs(root->left, path + "->" + to_string(root->left->val), res);

    if (root->right != NULL)
        dfs(root->right, path + "->" + to_string(root->right->val), res);
}
// 根-> 叶子节点路径
vector<string> binaryTreePaths(TreeNode* root) {
    vector<string> res;
    if (root == NULL) return res;
    dfs(root, to_string(root->val), res);
    return res;
}

vector<string> binaryTreePathsIteration(TreeNode* root) {
    //迭代方法
    vector<string> res;
    if (root == NULL) return res;
    stack<TreeNode*> s;
    stack<string> pathStack;
    s.push(root);
    pathStack.push(to_string(root->val));

    while (!s.empty()) {
        TreeNode * curNode = s.top(); s.pop();
        string tmpPath = pathStack.top(); pathStack.pop();

        if (curNode->left == NULL && curNode->right == NULL) {
            res.push_back(tmpPath); continue;
        }

        if (curNode->left != NULL) {
            s.push(curNode->left);
            pathStack.push(tmpPath + "->" + to_string(curNode->left->val));
        }

        if (curNode->right != NULL) {
            s.push(curNode->right);
            pathStack.push(tmpPath + "->" + to_string(curNode->right->val));
        }
    }
    return res;
}

int main() {

        TreeNode* p1 = new TreeNode(1);
        TreeNode* p2 = new TreeNode(2);
        TreeNode* p3 = new TreeNode(3);
        TreeNode* p4 = new TreeNode(4);
        TreeNode* p5 = new TreeNode(5);
        p1->left = p2;p1->right=p3;p3->left=p4;
        p4->right=p5;
        vector<TreeNode*> res;
        searchNodeRecursion(p1, p4, res);

        cout << "根节点到指定节点的路径递归方法：" << endl;
        reverse(res.begin(), res.end());
        for(auto &v: res) {
            cout << v->val << " ";
        }
        cout << endl;

        cout << "根节点到指定节点的路径迭代方法：" << endl;
        stack<TreeNode*> st = searchNodeIteration(p1, p5);
        while (!st.empty()) {
            cout << st.top()->val << " ";
            st.pop();
        }
        cout << endl;

        cout << "根节点到叶子节点的路径：" << endl;
        vector<string> str = binaryTreePaths(p1);
        for(auto &v: str) {
            cout << v << " ";
        }
        cout << endl;
        
    
    return 0;
}
