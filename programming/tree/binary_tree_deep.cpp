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

int depth(TreeNode* root) {
    return root ? max(depth(root->left), depth(root->right)) + 1 : 0;
}

int main() {
    /*
    *               1
    *              / \
    *             2   3
    *                /
    *               4
    */
    TreeNode* p1 = new TreeNode(1);
    TreeNode* p2 = new TreeNode(2);
    TreeNode* p3 = new TreeNode(3);
    TreeNode* p4 = new TreeNode(4);
    p1->left = p2;p1->right=p3;p3->left=p4;

    int res = depth(p1);
    cout << res << endl;
        
    return 0;
}
