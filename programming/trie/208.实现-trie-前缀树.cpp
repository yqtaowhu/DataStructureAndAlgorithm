/*
 * @lc app=leetcode.cn id=208 lang=cpp
 *
 * [208] 实现 Trie (前缀树)
 */

// @lc code=start
class TrieNode {
public:
	// Initialize your data structure here.
	bool isWord;
	TrieNode *next[26];
	TrieNode(){
		isWord = false;
		memset(next, NULL, sizeof(next));
	}
};

class Trie {
private:
    TrieNode* root;

public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* cur = root;
        for(int i=0; i<word.size(); i++) {
            if(cur->next[word[i]-'a'] == NULL) {
                //建立新节点
                TrieNode* nxt = new TrieNode();
                //指向节点
                cur->next[word[i]-'a'] = nxt;
            }
            cur = cur->next[word[i]-'a'];
        }
        cur->isWord = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode* cur = root;
        for(auto &c:word) {
            if(cur->next[c-'a']) {
                cur = cur->next[c-'a'];
            } else {
                return false;
            }
        }
        return cur->isWord;        
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
		TrieNode* cur = root;
		for (int i = 0; i<prefix.size() && cur; i++) {
			cur = cur->next[prefix[i] - 'a'];
		}
		return cur;
	}
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
// @lc code=end

