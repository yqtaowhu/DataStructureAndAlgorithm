#include <iostream>
#include "Queue.h"
using namespace std;
int main() {
	Queue<int> que;
	que.enQueue(1);
	que.enQueue(2);
	
	cout<<que.getFront()<<endl;
	que.deQueue();
	cout<<que.getFront()<<endl;
	
	cout << que.empty() << endl;
}