/*
 * @lc app=leetcode.cn id=295 lang=cpp
 *
 * [295] 数据流的中位数
 */

// @lc code=start
class MedianFinder {
public:
    /** initialize your data structure here. */

    //存放较小的一半元素，堆顶元素为该堆的最大值
    priority_queue<int> small;

    //存放较大的一半元素，堆顶元素为该堆的最小值
    priority_queue<int, vector<int>, greater<int>> large;

    void addNum(int num) {

        //元素一开始全都入堆small,然后将堆small的最大元素加入到堆large
        //这样可以保证堆small存放的是较小的一半元素，堆large存放的是较大的一半元素
        small.push(num);
        large.push(small.top());
        small.pop();

        //平衡两个堆的个数，使这两个堆具有特性a)或b)，即使得small的元素个数大于或等于large的元素个数
        if(large.size() > small.size()){
            small.push(large.top());
            large.pop();
        }
    }
    
    double findMedian() {
        return small.size() > large.size() ? double(small.top()) : (small.top()+large.top())*0.5; 
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
// @lc code=end

