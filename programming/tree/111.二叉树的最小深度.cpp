/*
 * @lc app=leetcode.cn id=111 lang=cpp
 *
 * [111] 二叉树的最小深度
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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */


// dfs

class Solution {
public:
    int minDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        if (root->right == nullptr) {
            return minDepth(root->left) + 1;
        }
        if (root->left == nullptr) {
            return minDepth(root->right) + 1;
        }
        return min(minDepth(root->left), minDepth(root->right)) + 1;
    }
};

// 自顶向下
class Solution {
public:
    int minDepth(TreeNode* root) {
        int ans = INT_MAX;
        auto dfs = [&](this auto&& dfs, TreeNode* node, int cnt) -> void {
            if (node == nullptr) {
                return;
            }
            cnt++;
            // 更新
            if (node->left == nullptr && node->right == nullptr) { // node 是叶子
                ans = min(ans, cnt);
                return;
            }
            dfs(node->left, cnt);
            dfs(node->right, cnt);
        };
        dfs(root, 0);
        return root ? ans : 0;
    }
};


// bfs
class Solution {
public:
    int minDepth(TreeNode* root) {
        if(!root) return 0;
    
        queue<TreeNode*> que;
        que.push(root);
        int depth = 0;
        
        while(!que.empty()) {
            int size = que.size();
            depth++;
            // 将一层的节点全部取出
            for(int i=0; i<size; i++) {
                root = que.front();
                que.pop();
                // 提前退出
                if(root->left == nullptr && root->right == nullptr) {
                    return depth;
                }
                if(root->left) {
                    que.push(root->left);
                }
                if(root->right) {
                    que.push(root->right);
                }
            }
        }
        return depth; 
    }
};
// @lc code=end

