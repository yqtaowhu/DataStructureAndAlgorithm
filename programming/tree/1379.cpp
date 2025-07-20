// dfs
class Solution {
public:
    TreeNode *getTargetCopy(TreeNode *original, TreeNode *cloned, TreeNode *target) {
        if (original == nullptr) {
            return nullptr;
        }
        if (original == target) {
            return cloned;
        }
        TreeNode *left = getTargetCopy(original->left, cloned->left, target);
        if (left != nullptr) {
            return left;
        }
        return getTargetCopy(original->right, cloned->right, target);
    }
};


// bfs
class Solution {
public:
    TreeNode *getTargetCopy(TreeNode *original, TreeNode *cloned, TreeNode *target) {
        queue<TreeNode *> q1, q2;
        q1.push(original);
        q2.push(cloned);
        while (!q1.empty()) {
            TreeNode *node1 = q1.front(), *node2 = q2.front();
            q1.pop();
            q2.pop();
            if (node1 == target) {
                return node2;
            }
            if (node1->left != nullptr) {
                q1.push(node1->left);
                q2.push(node2->left);
            }
            if (node1->right != nullptr) {
                q1.push(node1->right);
                q2.push(node2->right);
            }
        }
        return nullptr; // impossible case
    }
};