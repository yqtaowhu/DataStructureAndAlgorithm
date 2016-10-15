#include "LinkList.h"
int main() {
	vector<int> arr = { 1,2,3,4,5 };
	LinkList<int> list;

	list.creatList(arr);   //测试创建链表
	list.printList();

	cout << list.getLen() << endl;   //获得长度

	list.insElem(5, 6);    //在第五个位置插入6
	list.printList();

	list.delElem(5);    //删除位置为5的元素
	list.printList();

	cout <<boolalpha<< list.empty() << endl;   //判断是否为空
}