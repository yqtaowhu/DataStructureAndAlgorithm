/*
 * @lc app=leetcode.cn id=211 lang=cpp
 *
 * [211] 添加与搜索单词 - 数据结构设计
 */

// @lc code=start
struct Node{
    bool isWord = false;
    Node * next[26] = {};
};

class WordDictionary {
public:
    Node * root;
    WordDictionary() {
        root = new Node(); 
    }
    /** Adds a word into the data structure. */
    void addWord(string word) {
        Node* p = root;
        for(int i = 0;root&&i<word.size();++i){
            if(p->next[word[i]-'a'] == NULL){
                p->next[word[i]-'a'] = new Node();
            }
            p = p->next[word[i]- 'a'];
        }
        p->isWord  = true;
    }
    

    bool dfs(Node* root,string word,int i){
        if(!root) return false;
        if(i>= word.size()) return root->isWord;
        if(word[i]!='.'){
            if(root->next[word[i]-'a'])
                return dfs(root->next[word[i]-'a'],word,i+1);
            else 
                return false;
        }
        for(int j = 0;j<26;++j){
            if(root->next[j]&&dfs(root->next[j],word,i+1)){
                return true;
            }
        }
        return false;
    }
    
    bool search(string word) {
        return dfs(root,word,0);
    }
};
/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
// @lc code=end

