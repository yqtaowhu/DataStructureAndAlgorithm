// @lc code=start
// 解法一：反序中序遍历（类成员变量写法）
class Solution {
public:
    int sum = 0;

    TreeNode* convertBST(TreeNode* root) {
        if (root != nullptr) {
            convertBST(root->right);
            sum += root->val;
            root->val = sum;
            convertBST(root->left);
        }
        return root;
    }
};

// 解法二：模板方法（对应 bst_template.md 模板 5：中序有序性应用骨架）
//   反中序（右 → 根 → 左）遍历，用引用参数 sum 替代类成员，函数可重入
class Solution2 {
public:
    // 反中序遍历骨架：改「处理」部分即可适配不同 BST 中序题
    void dfs(TreeNode* root, int& sum) {
        if (!root) return;
        dfs(root->right, sum);   // 1. 先右子树（更大的值）
        // ===== 处理当前节点 =====
        sum += root->val;        // 2. 累加
        root->val = sum;         // 3. 覆盖为「≥ 当前值的和」
        // ========================
        dfs(root->left, sum);    // 4. 再左子树
    }

    TreeNode* convertBST(TreeNode* root) {
        int sum = 0;
        dfs(root, sum);
        return root;
    }
};
// @lc code=end