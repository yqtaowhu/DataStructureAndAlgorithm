class Solution {
public:
    /*
     * 思路：把「找中位数」转化为「找一条切割线」，把两个数组各自切成左右两半，
     *       再把 nums1 的左半 + nums2 的左半 拼成「总左半」，右边同理拼成「总右半」。
     *
     * 合法切割需要满足两个条件：
     *   1) 总左半的元素个数 = (m + n + 1) / 2   （奇数时让左半多 1 个，就是中位数）
     *   2) 总左半的最大值 ≤ 总右半的最小值       （保证左右两半有序拼接）
     *
     * 由于 nums1、nums2 内部已经有序，条件 2 等价于：
     *       nums1[i-1] ≤ nums2[j]  且  nums2[j-1] ≤ nums1[i]
     *
     * 又因为 i + j 是固定的（= halfLen），所以只需要在 nums1 上二分 i 即可，j 由 i 推出。
     *
     * 时间复杂度：O(log(min(m, n)))    空间复杂度：O(1)
     */
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // 保证 nums1 是「较短」的那个数组：
        //   1) 二分范围更小，效率更高；
        //   2) 由 i 推出的 j = halfLen - i 一定非负，避免越界。
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }

        int m = nums1.size();
        int n = nums2.size();
        int halfLen = (m + n + 1) / 2;   // 总左半应有的元素个数

        // 在 nums1 上二分切割位置 i，i 的含义：nums1 中放进「总左半」的元素个数
        // 取值范围 [0, m]，闭区间二分
        int left = 0, right = m;

        while (left <= right) {
            int i = left + (right - left) / 2;   // nums1 的切割位置
            int j = halfLen - i;                 // nums2 的切割位置（由 i 唯一确定）

            // 四个边界值：把越界的一侧视作 ±∞，可以统一比较逻辑，免去大量 if
            int L1 = (i == 0) ? INT_MIN : nums1[i - 1];   // nums1 左半的最大值
            int R1 = (i == m) ? INT_MAX : nums1[i];       // nums1 右半的最小值
            int L2 = (j == 0) ? INT_MIN : nums2[j - 1];   // nums2 左半的最大值
            int R2 = (j == n) ? INT_MAX : nums2[j];       // nums2 右半的最小值

            if (L1 > R2) {
                // nums1 左半放多了，切割线要往左移
                right = i - 1;
            } else if (L2 > R1) {
                // nums1 左半放少了，切割线要往右移
                left = i + 1;
            } else {
                // 找到合法切割：L1 ≤ R2 且 L2 ≤ R1
                //   总左半的最大值 = max(L1, L2)
                //   总右半的最小值 = min(R1, R2)
                if ((m + n) % 2 == 1) {
                    // 总长度为奇数：中位数 = 总左半的最大值（因为左半多放了 1 个）
                    return max(L1, L2);
                } else {
                    // 总长度为偶数：中位数 = (左半最大 + 右半最小) / 2
                    return (max(L1, L2) + min(R1, R2)) / 2.0;
                }
            }
        }
        return 0.0;   // 输入合法时不会走到这里
    }
};