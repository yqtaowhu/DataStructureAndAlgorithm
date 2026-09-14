# 二叉搜索树（BST）C++ 模板与全景题解

> BST 的核心性质：**左子树所有值 < 根 < 右子树所有值**，中序遍历严格递增。
> 所有 BST 题目都围绕两个方向展开：**利用有序性（中序）** 或 **利用值域剪枝（递归走向）**。
> 二叉树通用模板见 [tree_template.md](tree_template.md)，本篇聚焦 **BST 专属模板 + 全部题目 + 最优解**。

---

## 一、BST 核心性质速查

| 性质 | 描述 | 应用场景 |
|------|------|----------|
| **中序有序** | 中序遍历结果严格递增 | 验证 BST、第 k 小、最小差、众数、累加树、恢复 BST |
| **值域剪枝** | 比较 `root->val` 与目标值即可确定搜索方向 | 搜索、插入、删除、LCA、范围和、修剪 |
| **区间约束** | 每个节点有隐含的 `(lower, upper)` 合法区间 | 验证 BST、前序构造 BST、序列化 |
| **后继/前驱** | 中序后继 = 右子树最左节点；中序前驱 = 左子树最右节点 | 删除（双子节点）、中序后继查找 |

---

## 二、六大 BST 模板

### 模板 1：搜索（Search）

利用 BST 值域性质，每次比较排除一半子树，时间 O(h)。

```cpp
// 迭代版 —— 最简洁
TreeNode* searchBST(TreeNode* root, int val) {
    while (root && root->val != val) {
        root = (val < root->val) ? root->left : root->right;
    }
    return root;
}

// 递归版
TreeNode* searchBST(TreeNode* root, int val) {
    if (!root || root->val == val) return root;
    return (val < root->val) ? searchBST(root->left, val)
                             : searchBST(root->right, val);
}
```

### 模板 2：插入（Insert）

递归走到空位，新建节点挂上即可。

```cpp
TreeNode* insertIntoBST(TreeNode* root, int val) {
    if (!root) return new TreeNode(val);        // 找到空位，插入
    if (val < root->val)
        root->left  = insertIntoBST(root->left,  val);
    else
        root->right = insertIntoBST(root->right, val);
    return root;
}
```

### 模板 3：删除（Delete）—— 三种情况

删除是 BST 最复杂的操作，分三种情况处理：

```cpp
// 辅助：找子树最小节点（中序后继）
TreeNode* getMin(TreeNode* node) {
    while (node->left) node = node->left;
    return node;
}

TreeNode* deleteNode(TreeNode* root, int key) {
    if (!root) return nullptr;
    if (root->val == key) {
        // 情况 1：叶子 / 只有一个孩子 → 用孩子（可能为 null）顶替
        if (!root->left) return root->right;
        if (!root->right) return root->left;
        // 情况 2：左右孩子都在 → 用右子树最小节点（后继）替换
        TreeNode* minNode = getMin(root->right);
        root->right = deleteNode(root->right, minNode->val); // 先删后继
        minNode->left  = root->left;                          // 接上左子树
        minNode->right = root->right;                         // 接上右子树
        return minNode;
    } else if (key < root->val) {
        root->left  = deleteNode(root->left,  key);
    } else {
        root->right = deleteNode(root->right, key);
    }
    return root;
}
```

> **要点**：双子节点删除也可用「左子树最大节点（前驱）」替换，效果等价。

### 模板 4：验证 BST（两种方法）

**方法 A：递归传区间 `(lower, upper)`** —— 每个节点必须在开区间内。

```cpp
bool validate(TreeNode* root, long long lower, long long upper) {
    if (!root) return true;
    if (root->val <= lower || root->val >= upper) return false;
    return validate(root->left, lower, root->val)
        && validate(root->right, root->val, upper);
}
bool isValidBST(TreeNode* root) {
    return validate(root, LLONG_MIN, LLONG_MAX);
}
```

**方法 B：中序遍历检查严格递增** —— 前一个值必须 < 当前值。

```cpp
bool isValidBST(TreeNode* root) {
    stack<TreeNode*> st;
    long long prev = LLONG_MIN;
    while (root || !st.empty()) {
        while (root) { st.push(root); root = root->left; }
        root = st.top(); st.pop();
        if (root->val <= prev) return false;
        prev = root->val;
        root = root->right;
    }
    return true;
}
```

> **注意**：`prev` 必须用 `long long` 防止 `INT_MIN` 节点值导致误判。

### 模板 5：中序有序性应用（BST 万能骨架）

凡涉及「BST + 大小/顺序/第 k/差值/累加」，**先想中序遍历**。

```cpp
// 通用中序骨架 —— 修改 "处理" 部分即可适配不同题目
void inorder(TreeNode* root, /* 状态变量 */) {
    if (!root) return;
    inorder(root->left, /* 状态变量 */);
    // ===== 处理当前节点 =====
    //   230 第 k 小：计数到 k 返回
    //   530 最小差：abs(cur - prev) 取 min
    //   501 众数：统计连续相等长度
    //   538 累加树：反中序（右→根→左）累加
    //   99  恢复 BST：找逆序对
    //   36  双向链表：prev 串接
    // ========================
    inorder(root->right, /* 状态变量 */);
}
```

### 模板 6：值域递归剪枝（BST 特有）

利用 BST 值域性质，**不需要遍历全树**，仅递归包含目标的子树。

```cpp
// 通用骨架：根据 root->val 与目标范围的关系决定递归方向
int/TreeNode* bstPrune(TreeNode* root, /* 目标参数 */) {
    if (!root) return /* 基础情况 */;
    // 当前值 > 目标上界 → 答案一定在左子树
    // 当前值 < 目标下界 → 答案一定在右子树
    // 当前值在范围内 → 合并左右子树结果 + 当前节点
}
```

**典型应用：**
- **235 BST 最近公共祖先**：p、q 分居两侧即答案
- **938 范围和**：`val` 在 `[low, high]` 内则累加，否则只走一侧
- **669 修剪 BST**：`val < low` 丢弃左子树，`val > high` 丢弃右子树

---

## 三、模板选择决策树

```
题目涉及 BST？
├─ 搜索 / 插入 / 删除？ → 模板 1 / 2 / 3（值域走向）
├─ 验证 / 恢复 BST？   → 模板 4（区间约束 or 中序递增）
├─ 第 k 小 / 最小差 / 众数 / 累加 / 链表？ → 模板 5（中序有序性）
├─ LCA / 范围和 / 修剪？ → 模板 6（值域递归剪枝）
├─ 有序数组/链表构造 BST？ → 分治取中点
└─ 前序构造 BST？ → 区间上界法（模板 4 变体）
```

---

## 四、LeetCode BST 全景题表

> 链接指向本仓库已有题解（`tree/` 目录）。所有题最优时间 O(n) 或 O(h)，除注明外空间 O(h)（递归栈）。

### A. 基础操作：搜索 / 插入 / 删除（模板 1 / 2 / 3）

| 题目 | 核心思路 | 复杂度 |
|------|----------|--------|
| [700. BST 中搜索](700.二叉搜索树中的搜索.cpp) | 比较值走左/右，迭代一行 | O(h) |
| [701. BST 中插入](701.二叉搜索树中的插入操作.cpp) | 递归到空位新建节点 | O(h) |
| [450. 删除 BST 节点](450.删除二叉搜索树中的节点.cpp) | 叶/单子直接删；双子用后继替换 | O(h) |

### B. 验证与修复（模板 4）

| 题目 | 核心思路 | 复杂度 |
|------|----------|--------|
| [98. 验证 BST](98.验证二叉搜索树.cpp) | 中序严格递增 or 递归传 `(lower, upper)` | O(n) |
| [99. 恢复 BST](99.恢复二叉搜索树.cpp) | 中序找两个逆序对，交换错位节点值；Morris O(1) 空间 | O(n) |

### C. 中序有序性应用（模板 5）

| 题目 | 核心思路 | 复杂度 |
|------|----------|--------|
| [230. BST 第 k 小](230.二叉搜索树第k小的数.cpp) | 中序计数到 k 提前返回 | O(h+k) |
| [530. BST 最小绝对差](530.二叉搜索树的最小绝对差.cpp) | 中序相邻作差取 min | O(n) |
| [783. BST 节点最小距离](https://leetcode.cn/problems/minimum-distance-between-bst-nodes/) | 同 530，完全一样 | O(n) |
| [538. 转累加树](538.把二叉搜索树转换为累加树.cpp) | **反中序**（右→根→左）累加后缀和 | O(n) |
| [501. BST 中的众数](501.二叉搜索树中的众数.cpp) | 中序统计连续相等长度，更新最大频次 | O(n) / O(1) 额外 |
| [173. BST 迭代器](173.二叉搜索树迭代器.cpp) | 栈维护左链，`next()` 均摊 O(1) | next O(1) 均摊 |
| [897. 递增顺序搜索树](897.递增顺序搜索树.cpp) | 中序用 prev 串成右斜链 | O(n) |
| [36. BST 与双向链表](36.二叉搜索树与双向链表.md) | 中序 prev 串成环状双向链表 | O(n) |

### D. 值域递归剪枝（模板 6）

| 题目 | 核心思路 | 复杂度 |
|------|----------|--------|
| [235. BST 最近公共祖先](235.二叉搜索树最近公共祖先.cpp) | p、q 都小于 root 走左，都大于走右，否则当前即答案 | O(h) |
| [938. BST 范围和](938.二叉搜索树的范围和.cpp) | `val < low` 只走右，`val > high` 只走左，在范围内累加+双侧 | O(n) |
| [669. 修剪 BST](669.修剪二叉搜索树.cpp) | `val < low` 返回修剪后的右子树，`val > high` 返回修剪后的左子树 | O(n) |

### E. 构造 BST

| 题目 | 核心思路 | 复杂度 |
|------|----------|--------|
| [108. 有序数组转 BST](108.将有序数组转换为二叉搜索树.cpp) | 取中点为根，左右半递归 → 天然平衡 | O(n) |
| [109. 有序链表转 BST](109.有序链表转换二叉搜索树.cpp) | 快慢指针找中点；或中序模拟 O(n) | O(n) |
| [1008. 前序构造 BST](1008.前序遍历构造二叉搜索树.cpp) | 区间上界法：用 `upper` 约束递归边界，线性构造 | O(n) |
| [96. 不同的 BST 数量](https://leetcode.cn/problems/unique-binary-search-trees/) | 卡特兰数 DP：`G(n) = Σ G(i-1)*G(n-i)` | O(n²) |
| [95. 不同的 BST II](https://leetcode.cn/problems/unique-binary-search-trees-ii/) | 枚举根 `i`，左 `[lo,i-1]` 右 `[i+1,hi]` 递归构造 | O(4ⁿ/√n) |

### F. 序列化 / 变形

| 题目 | 核心思路 | 复杂度 |
|------|----------|--------|
| [449. 序列化 BST](https://leetcode.cn/problems/serialize-and-deserialize-bst/) | 仅存前序，反序列化用区间上界法（同 1008） | O(n) |
| [1382. 将 BST 变平衡](https://leetcode.cn/problems/balance-a-binary-search-tree/) | 中序取有序数组 → 分治取中点重建（同 108） | O(n) |

---

## 五、各题详解与代码

### 701. 二叉搜索树中的插入操作

**思路**：模板 2，递归走到 `nullptr` 时新建节点返回。

```cpp
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (!root) return new TreeNode(val);
        if (val < root->val)
            root->left  = insertIntoBST(root->left,  val);
        else
            root->right = insertIntoBST(root->right, val);
        return root;
    }
};
```

### 938. 二叉搜索树的范围和

**思路**：模板 6，利用值域剪枝，`val < low` 只递归右子树，`val > high` 只递归左子树。

```cpp
class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        if (!root) return 0;
        if (root->val < low) return rangeSumBST(root->right, low, high);
        if (root->val > high) return rangeSumBST(root->left, low, high);
        return root->val
             + rangeSumBST(root->left,  low, high)
             + rangeSumBST(root->right, low, high);
        }
};
```

### 669. 修剪二叉搜索树

**思路**：模板 6，后序修剪。当前值 < low 则整棵左子树和自身都不要，返回修剪后的右子树；> high 反之。

```cpp
class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        if (!root) return nullptr;
        if (root->val < low) return trimBST(root->right, low, high);
        if (root->val > high) return trimBST(root->left, low, high);
        root->left  = trimBST(root->left,  low, high);
        root->right = trimBST(root->right, low, high);
        return root;
    }
};
```

### 501. 二叉搜索树中的众数

**思路**：模板 5，中序遍历时统计连续相等值的长度。BST 中序有序，相同值一定相邻。

```cpp
class Solution {
public:
    vector<int> res;
    int maxCount = 0, curCount = 0;
    TreeNode* prev = nullptr;

    void inorder(TreeNode* root) {
        if (!root) return;
        inorder(root->left);
        // 处理当前节点
        curCount = (prev && prev->val == root->val) ? curCount + 1 : 1;
        if (curCount == maxCount) {
            res.push_back(root->val);
        } else if (curCount > maxCount) {
            maxCount = curCount;
            res = {root->val};
        }
        prev = root;
        inorder(root->right);
    }

    vector<int> findMode(TreeNode* root) {
        inorder(root);
        return res;
    }
};
```

### 897. 递增顺序搜索树

**思路**：模板 5，中序遍历过程中用 `prev` 指针将节点串成只有右孩子的链。

```cpp
class Solution {
public:
    TreeNode* prev = nullptr;

    TreeNode* increasingBST(TreeNode* root) {
        if (!root) return nullptr;
        TreeNode* dummy = new TreeNode(0);
        prev = dummy;
        inorder(root);
        return dummy->right;
    }

    void inorder(TreeNode* root) {
        if (!root) return;
        inorder(root->left);
        prev->right = root;
        root->left = nullptr;   // 断开左指针
        prev = root;
        inorder(root->right);
    }
};
```

### 1008. 前序遍历构造二叉搜索树

**思路**：前序首元素为根，利用区间上界 `upper` 约束递归。若下一个元素 < upper 则为左子树，否则回溯到父节点的右子树。

```cpp
class Solution {
public:
    int idx = 0;

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return build(preorder, INT_MAX);
    }

    TreeNode* build(vector<int>& preorder, int upper) {
        if (idx >= preorder.size() || preorder[idx] > upper)
            return nullptr;
        TreeNode* root = new TreeNode(preorder[idx++]);
        root->left  = build(preorder, root->val);   // 左子树上界 = 根值
        root->right = build(preorder, upper);        // 右子树上界 = 父节点上界
        return root;
    }
};
```

### 96. 不同的二叉搜索树（卡特兰数）

**思路**：DP，`G(n)` 表示 `1..n` 构成的 BST 种数。枚举根 `i`，左子树 `G(i-1)`，右子树 `G(n-i)`。

```cpp
class Solution {
public:
    int numTrees(int n) {
        vector<int> G(n + 1, 0);
        G[0] = G[1] = 1;
        for (int i = 2; i <= n; i++)
            for (int j = 1; j <= i; j++)
                G[i] += G[j - 1] * G[i - j];
        return G[n];
    }
};
```

---

## 六、记忆口诀

> **BST 三板斧：搜/插/删走值域，验证传区间，有序想中序。**
> **删除双子找后继（右子树最左），范围和/修剪/LCA 靠剪枝。**
> **构造取中点（108/109），前序用上界（1008），计数卡特兰（96）。**

---

## 附：改一处，解决一类 BST 问题

| 问题 | 用哪个模板 | 改什么 |
|------|-----------|--------|
| 700 搜索 | 模板 1 | 无需改 |
| 701 插入 | 模板 2 | 无需改 |
| 450 删除 | 模板 3 | 三种情况分支 |
| 98 验证 | 模板 4 | 中序检查 `prev < cur` 或递归传 `(lower, upper)` |
| 99 恢复 | 模板 4+5 | 中序找两个逆序对并交换 |
| 230 第 k 小 | 模板 5 | 中序计数到 k 返回 |
| 530/783 最小差 | 模板 5 | 中序相邻差取 min |
| 538 累加树 | 模板 5 | **反中序**（右→根→左）累加 |
| 501 众数 | 模板 5 | 中序统计连续相等长度 |
| 173 迭代器 | 模板 5 | 栈维护左链，`next()` 弹出处理 |
| 897 递增链 | 模板 5 | 中序 `prev->right = cur; cur->left = null` |
| 235 LCA | 模板 6 | p、q 分居两侧即答案 |
| 938 范围和 | 模板 6 | 三条件分支剪枝 |
| 669 修剪 | 模板 6 | 三条件分支 + 后序接回 |
| 108 数组→BST | 分治 | 取中点递归 |
| 1008 前序→BST | 模板 4 变体 | 区间上界法 |
