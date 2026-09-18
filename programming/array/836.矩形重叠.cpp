/*
 * @lc app=leetcode.cn id=836 lang=cpp
 *
 * [836] 矩形重叠
 */

// @lc code=start
class Solution {
public:
    // 方法1: 逆向思维，不重叠地方情况
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        return !(rec1[2] <= rec2[0] ||   // left
                 rec1[3] <= rec2[1] ||   // bottom
                 rec1[0] >= rec2[2] ||   // right
                 rec1[1] >= rec2[3]);    // top
    }
    // 方法2: 矩形有重叠，则其投影一定有重叠 
    /*
    x1, y1, x2, y2    x3,y3, x4, y4, 在x轴和y轴有重叠
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        return (min(rec1[2], rec2[2]) > max(rec1[0], rec2[0]) &&
                min(rec1[3], rec2[3]) > max(rec1[1], rec2[1]));
    }
    */
};
// @lc code=end

