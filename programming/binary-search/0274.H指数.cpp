// 274. H 指数
// 套模板解法（左闭右开 [left, right)，红蓝染色）
// 模板三句话：
//   1. 循环条件 left < right
//   2. 满足条件 → right = mid（mid 可能是答案，不能丢）
//   3. 不满足   → left = mid + 1（mid 一定不是答案，排除）
//
// 前提：先排序（275. H 指数 II 输入已升序，可去掉 sort）
// 红蓝染色视角：
//   红色（不满足）  : citations[mid] <  n - mid，mid 左侧引用太小，分界点在右
//   蓝色（满足条件）: citations[mid] >= n - mid，从 mid 到末尾可凑出 n-mid 篇
//   分界点 left 满足：[left, n) 共 n-left 篇论文，引用均 >= n-left，即答案

class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());
        int n = citations.size();
        int left = 0, right = n;   // 左闭右开
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (citations[mid] >= n - mid) {
                right = mid;      // mid 可能是分界点，不能丢
            } else {
                left = mid + 1;   // mid 一定不是分界点
            }
        }
        return n - left;          // 注意：答案是篇数 n-left，不是 citations[left]
    }
};
