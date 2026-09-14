/*
 * @lc app=leetcode.cn id=297 lang=cpp
 *
 * [297] 二叉树的序列化与反序列化
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
class Codec {
public:
    // ---------- 序列化：前序遍历，空节点用 "#" 占位，逗号分隔 ----------
    void serializeHelper(TreeNode* root, string& out) {
        if (!root) { out += "#,"; return; }        // 空节点也要记录，才能唯一确定结构
        out += to_string(root->val) + ",";
        serializeHelper(root->left, out);
        serializeHelper(root->right, out);
    }

    string serialize(TreeNode* root) {
        string out;
        serializeHelper(root, out);
        return out;
    }

    // ---------- 反序列化：按前序顺序从队列取 token 重建 ----------
    TreeNode* deserializeHelper(queue<string>& tokens) {
        string t = tokens.front(); tokens.pop();
        if (t == "#") return nullptr;              // 遇到占位符，还原为空节点
        TreeNode* node = new TreeNode(stoi(t));
        node->left  = deserializeHelper(tokens);   // 先建左子树，再建右子树（前序顺序）
        node->right = deserializeHelper(tokens);
        return node;
    }

    TreeNode* deserialize(string data) {
        queue<string> tokens;
        string cur;
        for (char c : data) {                      // 按逗号切分成 token 队列
            if (c == ',') { tokens.push(cur); cur.clear(); }
            else cur += c;
        }
        return deserializeHelper(tokens);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
// @lc code=end
