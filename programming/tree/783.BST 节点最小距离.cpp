/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
// @lc code=start
// 解法一：迭代栈版中序遍历
class Solution {
public:
    int minDiffInBST(TreeNode* root) {
        if(!root) return 0;
        int last = -1e5, res = INT_MAX;
        stack<TreeNode*> st;
        while(root || !st.empty()) {
            while(root) {
                st.push(root);
                root = root->left;
            }
            root = st.top();
            st.pop();
            res = min(res, root->val - last);
            last = root->val;
            root = root->right;
        }
        return res;
    }
};

// 解法二：模板方法（对应 bst_template.md 模板 5：中序有序性应用骨架）
//   与 530 完全一致，prev 和 ans 均用引用参数传递
class Solution2 {
public:
    void inorder(TreeNode* root, TreeNode*& prev, int& ans) {
        if (!root) return;
        inorder(root->left, prev, ans);
        // ===== 处理当前节点：与前驱作差取 min =====
        if (prev) ans = min(ans, root->val - prev->val);
        prev = root;
        // ========================
        inorder(root->right, prev, ans);
    }

    int minDiffInBST(TreeNode* root) {
        TreeNode* prev = nullptr;
        int ans = INT_MAX;
        inorder(root, prev, ans);
        return ans;
    }
};
// @lc code=end