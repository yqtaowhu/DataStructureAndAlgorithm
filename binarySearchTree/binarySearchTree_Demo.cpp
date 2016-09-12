#include "binarySearchTree.h"
#include<vector>
int main() {
	vector<int> v = { 15,20,4,1,16 ,24};
	BST<int> bst;
	for (auto c : v)
		bst.insert(c);    //insert

	bst.inorder();        //inorder traveral
	bst.morris_inorder();
	bst.breadFirst();     //level traveral
	//delete
	bst.findAndDelete(15);
	bst.breadFirst();
	//search
	BSTNode<int>* node=bst.search(16);
	cout << node->val << endl;
}