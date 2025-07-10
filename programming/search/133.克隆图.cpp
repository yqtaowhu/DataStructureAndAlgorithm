/*
 * @lc app=leetcode.cn id=133 lang=cpp
 *
 * [133] 克隆图
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
class Solution {
public:
    Node* cloneGraph(Node* node) {
		if ( !node )  return NULL;
		
        queue<Node *> m_queue;	//利用队列实现图的广度优先遍历
		map<Node *,Node *> m_map;
		Node *temp;
		Node *p;
		
		m_queue.push(node);	 //第一个结点入队
		
		//首先BFS所有节点，创建新节点，并保存新节点与原节点的映射关系
		while(!m_queue.empty()){
			//出队元素
			temp = m_queue.front();
			m_queue.pop();
			//新节点创建
			p = new Node(temp->val,{});
			m_map.insert({temp,p});
			//入队元素
			for( Node *neighborsNode : temp->neighbors ) {
				if( m_map.find(neighborsNode) == m_map.end() ) {  //如果该节点已经有了映射关系，则不入队
					m_queue.push(neighborsNode);
				}
			}
		}
		
		//遍历所有节点 完成边的链接
		map<Node *,Node *>::iterator iter;
		for( iter = m_map.begin(); iter != m_map.end(); ++iter ){
			for( Node *neighborsNode : iter->first->neighbors ) {
				iter->second->neighbors.push_back(m_map.find(neighborsNode)->second);
			}
		}
		
		return m_map.find(node)->second;
    }
};
// @lc code=end

