/*
*               6
*              /  \
*             2    8
*            / \  / \
*           0  4 7   9
* Q1. 求二叉搜索树的最近公共祖先:https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/
* Q2. 普通的二叉树:https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/
* 
*/
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


/************************************************************************************
求解二叉搜索树的最近公共祖先:
根据根节点和其他两个节点的关系即可判断
***********************************************************************************/
TreeNode* lowestCommonAncestorForBSTRecursion(TreeNode* root, TreeNode* p, TreeNode* q) {
        //根据二叉搜索树的性质即可,3种情况
        if (p->val < root->val && q->val < root->val) {
            return lowestCommonAncestorForBSTRecursion(root->left, p, q);
        }
        if (p->val > root->val && q->val > root->val) {
            return lowestCommonAncestorForBSTRecursion(root->right, p, q);
        }
        return root;
}

TreeNode* lowestCommonAncestorForBSTIteration(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* cur = root;
        while (true) {
            if (p -> val < cur -> val && q -> val < cur -> val) {
                cur = cur -> left;
            } else if (p -> val > cur -> val && q -> val > cur -> val) {
                cur = cur -> right;
            } else {
                break;
            }
        }
        return cur;
}

/************************************************************************************
求二叉树的最近公共祖先,例如 2，4
方法1： 找到根节点到2,4的路径
6  2
6  2  4
所以从短的路径最后开始遍历，查找相同的节点，就是其公共的祖先，2

方法2： 直接dfs 
***********************************************************************************/
// 方法1：
bool dfs(TreeNode* root, TreeNode* des, vector<TreeNode*> &path) {
    if (root == nullptr)
        return false;
    if (root == des) {
        path.push_back(root);
        return true;
    }
    if (dfs(root->left, des, path) || dfs(root->right, des, path)) {
        path.push_back(root);
        return true;
    }
    return false;
}

TreeNode* lowestCommonAncestorCommonTree(TreeNode* root, TreeNode* p, TreeNode* q) {
    vector<TreeNode*> path_p, path_q;
    dfs(root, p, path_p);
    dfs(root, q, path_q);
    reverse(path_p.begin(), path_p.end());
    reverse(path_q.begin(), path_q.end());

    int n = min(path_p.size(), path_q.size());
    for (int i = n - 1; i >= 0; i--)
        if (path_p[i] == path_q[i])
            return path_p[i];

    return nullptr;
}

//方法2
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if(root == nullptr || root == p || root == q) {
        return root;
    }
    TreeNode* left = lowestCommonAncestor(root->left, p, q);
    TreeNode* right = lowestCommonAncestor(root->right, p, q);
    if(left && right) {
        return root;
    }
    return left ? left : right;
}

int main() {
    TreeNode* p1 = new TreeNode(6);
    TreeNode* p2 = new TreeNode(2);
    TreeNode* p3 = new TreeNode(8);
    TreeNode* p4 = new TreeNode(0);
    TreeNode* p5 = new TreeNode(4);
    TreeNode* p6 = new TreeNode(7);
    TreeNode* p7 = new TreeNode(9);
    p1->left = p2;p1->right= p3;
    p2->left = p4;p2->right= p5;
    p3->left = p6;p3->right= p7;
    //TreeNode* res = lowestCommonAncestorForBSTRecursion(p1, p2, p4);
    //cout << "p2, p4最近公共祖先为" << res->val << endl;

    TreeNode* res2 = lowestCommonAncestorCommonTree(p1, p2, p4);
    cout << "p2, p4最近公共祖先为" << res2->val << endl;
    
    return 0;
}
