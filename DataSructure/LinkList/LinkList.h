//Author	: yqtao
//date		: 2016.09.06
//Email		: yqtao@whu.edu.cn
#ifndef MY_LINKLIST_H
#define MY_LINKLIST_H
#include<vector>
#include<iostream>
using namespace std;
template <typename T> class LinkList
{
	/*
	define the listnode
	*/
	template<typename T> struct ListNode
	{
		T val;
		ListNode<T> *next;
		ListNode<T>(int x): val(x){}
	};
private:
	ListNode<T>* head;  //一个伪结点，便于操作
public:
	LinkList<T>() {      //creat a null list
		head = new ListNode<T>(0); head->next = nullptr;
	}   
	//~LinkList<T>();
	//creat list by a array
	void creatList(vector<T>& arr);  
	//insert x at position i;
	void insElem(int i, T x); 
	//get list length
	int getLen();    
	//delete a  node at pisition i
	T delElem(int i);
	//check empty
	bool empty() { return !head->next; }
	void printList() {
		ListNode<T>* tmp = head->next;
		while (tmp) {
			cout << tmp->val<<" ";
			tmp = tmp->next;
		}
		cout << endl;
		delete tmp;
	}
};
template<typename T>                   //头插法建立链表
void LinkList<T>::creatList(vector<T>& arr) {
	ListNode<T>* s;
	head = new ListNode<T>(0);
	head->next = nullptr;
	for (int i = arr.size()-1; i>=0; i--) {
		s = new ListNode<T>(arr[i]);
		s->next = head->next;
		head->next = s;
	}
}
template<typename T>
int LinkList<T>::getLen() {
	int len = 0;
	ListNode<T>* p; p = head->next;
	while (p) {
		len++;
		p = p->next;
	}
	return len;
}
template<typename T>
void LinkList<T>::insElem(int i, T x) {    //example :  1 2 3 4 5 
	if (i <0 || i > getLen())               //i=<0,5> 即插入后i所在的位置
		throw "wrong positon";
	ListNode<T>* p = head;
	for (int j = 0; j < i; j++) {
		p = p->next;
	}
	ListNode<T>* tmp = new ListNode<T>(x);
	tmp->next=p->next;
	p->next = tmp;
}
template<typename T>
T LinkList<T>::delElem(int i) {
	if (i < 0 || i >= getLen())
		throw "wrong position";
	ListNode<T>* p = head;
	for (int j = 0; j < i; j++) {
		p = p->next;
	}
	ListNode<T>* q =p->next;
	p->next = q->next;
	delete q;
}
#endif
