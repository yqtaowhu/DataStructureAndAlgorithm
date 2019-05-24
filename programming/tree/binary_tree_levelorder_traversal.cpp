#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/*
        3
       / \
      9  20
        /  \
       15   7
1. 求二叉树的层序遍历结果：
[
  [3],
  [9,20],
  [15,7]
]
*/


vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int> > res;
    if (!root) return res;
    queue<TreeNode*> que;
    que.push(root);
    while (!que.empty()) {
        int size = que.size();
        vector<int> v(size,0);
        // 每次处理一层的数据
        for (int i = 0; i < size; ++i) {
            root = que.front();
            que.pop();
            v[i] = root->val;
            if (root->left)
                que.push(root->left);
            if (root->right)
                que.push(root->right);
        }
        res.push_back(v);
    }
    return res;
}

int main() {
    
    TreeNode* p1 = new TreeNode(3);
    TreeNode* p2 = new TreeNode(9);
    TreeNode* p3 = new TreeNode(20);
    TreeNode* p4 = new TreeNode(15);
    TreeNode* p5 = new TreeNode(7);
    p1->left = p2;p1->right=p3;p3->left=p4;p3->right=p5;
    vector<vector<int> > res = levelOrder(p1);
    for (auto &l: res) {
        for (auto &v:l) {
            cout << v << " " << endl;
        }
        cout << endl;
    }
    return 0;
}
