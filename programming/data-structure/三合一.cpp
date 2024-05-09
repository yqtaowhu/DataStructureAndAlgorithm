class TripleInOne {
public:
    vector<int> arr; // 存储所有栈中的元素
    vector<int> ptrs; //  ptrs[i] 存储第 i 个栈中下一个需要填充的位置的索引，注意不是指向栈顶，而是栈顶的上面
    int stackSize;

    TripleInOne(int stackSize) {
        this->stackSize = stackSize;
        arr.resize(3 * stackSize);

        ptrs.resize(3);
        ptrs[0] = 0;
        ptrs[1] = stackSize;
        ptrs[2] = stackSize * 2;
    }
    
    // 用于向第 stackNum 个栈中压入元素 value。如果该栈未满，将元素存储在数组的对应位置，并将指针向后移动一个位置。
    void push(int stackNum, int value) {
        if (ptrs[stackNum] < (stackNum + 1) * stackSize) {
            arr[ptrs[stackNum]] = value;
            ptrs[stackNum]++;
        }
    }
    
    // 用于从第 stackNum 个栈中弹出栈顶元素。如果该栈不为空，将指针向前移动一个位置，并返回该位置上的元素。
    int pop(int stackNum) {
        if (isEmpty(stackNum)) return -1;
        ptrs[stackNum]--;
        return arr[ptrs[stackNum]];
    }
    
    // 用于获取第 stackNum 个栈的栈顶元素，但不会将其弹出。如果该栈不为空，返回该位置上的元素。
    int peek(int stackNum) {
        if (isEmpty(stackNum)) return -1;
        return arr[ptrs[stackNum] - 1];
    }
    
    // 用于检查第 stackNum 个栈是否为空。如果指针指向栈底，即该栈为空。
    bool isEmpty(int stackNum) {
        return  ptrs[stackNum] == stackSize * stackNum;
    }
};
