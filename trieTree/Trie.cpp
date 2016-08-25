//字典树
//用来统计以某个字符开头的单词个数
//2016.08.25
//yqtao@whu.edu.cn
#include <iostream>
#include <string>
using namespace std;
const int Num = 26;//
struct TrieNode{
	int n;		//记录以某些字母开头的个数，与判断是不是单词很像
	TrieNode* next[Num];
	TrieNode(){
		n = 0;//初始化,是用于统计的
		memset(next, NULL, sizeof(next));
	}
};
class Trie{
public:
	Trie() { root = new TrieNode(); }
	void insert(string &word);
	int search(string &word);
	void deleteTrie(TrieNode* root);
private:
	TrieNode* root;
};
//边插入边记录
void Trie::insert(string &word){
	TrieNode* location = root;
	location->n++;
	for (int i = 0; i < word.length(); i++){
		if (location->next[word[i] - 'a'] == nullptr){
			TrieNode* temp = new TrieNode();
			location->next[word[i] - 'a'] = temp;
		}
		location = location->next[word[i] - 'a'];
		location->n++;         //将记录数加1
	}

}
int Trie::search(string &word){
	TrieNode* location = root;
	//while (word&&location)//注意location不能为空
	for (int i = 0; i < word.length() && location; i++)
		location = location->next[word[i] - 'a'];
	if (location == nullptr)
		return 0;
	else
		return location->n;
}
void Trie::deleteTrie(TrieNode* root){
	for (int i = 0; i < Num; i++){
		if (root->next[i] != NULL){
			deleteTrie(root->next[i]);
		}
	}
	delete root;
}
void main() {
	Trie tree;
	string s1 = "babaab";
	string s2 = "babbbaaaa";
	string s3 = "abba";
	string s4 = "aaaaabaa";
	string s5 = "babaababb";
	tree.insert(s1);
	tree.insert(s2);
	tree.insert(s3);
	tree.insert(s4);
	tree.insert(s5);
	string s6 = "babb";
	tree.search(s6);	
}