/*
 * @lc app=leetcode.cn id=99 lang=cpp
 *
 * [99] 恢复二叉搜索树
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode *pre = new TreeNode(INT_MIN);
    TreeNode *first = nullptr, *second = nullptr;

    void dfs(TreeNode* root) {
        // 中序遍历
        if(!root) {
            return;
        }
        dfs(root->left);

        if(first == nullptr && pre->val > root->val) {
            first = pre;
        }
        if(first && pre->val > root->val) {
            second = root;
        }

        pre = root;

        dfs(root->right);
    }
    
    void recoverTree(TreeNode* root) {
        dfs(root);
        swap(first->val, second->val);
    }
};


class Solution {
public:
    void recoverTree(TreeNode* root) {
        stack<TreeNode*> st;
        TreeNode* cur = root;
        TreeNode* prev = nullptr;
        TreeNode* first = nullptr;
        TreeNode* second = nullptr;

        while (cur || !st.empty()) {
            // 一路压左链
            while (cur) {
                st.push(cur);
                cur = cur->left;
            }
            cur = st.top(); st.pop();

            // ===== 中序处理：找两个逆序对 =====
            if (prev && prev->val > cur->val) {
                if (!first) first = prev;   // 第一个逆序对的大值
                second = cur;               // 第二个逆序对的小值（相邻时也会覆盖正确）
            }
            prev = cur;
            // ================================

            cur = cur->right;
        }
        swap(first->val, second->val);
    }
};
// @lc code=end

