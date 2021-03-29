/*
 * @lc app=leetcode.cn id=146 lang=cpp
 *
 * [146] LRU 缓存机制
 */

// @lc code=start
struct Node {
    int key;
    Node* prev, *next;
    Node(int x): key(x), prev(nullptr), next(nullptr) {
    }
};

class LRUCache {
public:
    // 成员变量
    int total, cap;   // 当前大小和容量
    Node* head, *tail;     // 双向链表的头结点和尾节点
    unordered_map<int, pair<int, Node*>> dict; 
    
    LRUCache(int capacity) {
        cap = capacity;
        total = 0;
        head = new Node(-1);
        tail = new Node(-1);
        head->next = tail;
        tail->prev = head;
        cout << cap << endl;
    }
    
    int get(int key) {
        if(dict.find(key) == dict.end()) {
            return -1;
        }
        Node* cur = dict[key].second;
        // 将当前节点移到尾节点的前面
        // 1. 处理当前节点前后指针
        cur->prev->next = cur->next;
        cur->next->prev = cur->prev;
        // 2.  处理当前节点
        cur->next = tail;
        cur->prev = tail->prev;
        // 3. 处理tail节点, 和指向cur的节点
        tail->prev->next = cur;
        tail->prev = cur;

        return dict[key].first;
    }
    
    void put(int key, int value) {
        //cout << key << endl;
        if(dict.find(key) != dict.end()) {
            //cout << "find " << endl;
            // 找到了，比较简单，只需要考虑双向链表的变化
            dict[key].first = value;
            Node* cur = dict[key].second;
            // 将当前节点移到尾节点的前面, 和get完全相同
            // 1. 处理当前节点前后指针
            cur->prev->next = cur->next;
            cur->next->prev = cur->prev;
            // 2.  处理当前节点
            cur->next = tail;
            cur->prev = tail->prev;
            // 3. 处理tail节点, 和指向cur的节点
            tail->prev->next = cur;
            tail->prev = cur;
        } else {
            //cout << key << " " << total << " " << cap << endl;
            if(total == cap) {
                cout << key << endl;
                // 需要删除头结点后面的元素
                Node* cur = head->next;
                dict.erase(cur->key);

                head->next = cur->next;
                cur->next->prev = head;
                delete cur;
                total--;
                
            }
            // 新建节点插入到最后
            Node* cur = new Node(key);
            dict[key] = make_pair(value, cur);

            cur->next = tail;
            cur->prev = tail->prev;

            tail->prev->next = cur;
            tail->prev = cur;

            total++;
            
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end

