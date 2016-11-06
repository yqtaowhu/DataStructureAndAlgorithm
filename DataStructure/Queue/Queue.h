//Author	: yqtao
//date		: 2016.09.09
//Email		: yqtao@whu.edu.cn
/*
Implement my own queue,it is a sequence queue
*/
const int maxSize = 100;
template<typename T> class Queue
{
private:
	T data[maxSize];
	int front, rear;     //the queue point of head ,end
public:
	Queue() { front = rear = -1; }
	bool empty() { return front == rear; }
	void enQueue(T x);
	void deQueue();
	T getFront();      //get the front of queue
};
template<typename T>
void Queue<T>::enQueue(T x) {
	if (rear == maxSize - 1)
		throw "out of range";
	rear++;
	data[rear] = x;
}
//
template<typename T>
void Queue<T>::deQueue() {
	if (front == rear)
		throw "the queue is empty";
	front++;
}
//
template<typename T>
T Queue<T>::getFront() {
	if (rear == front) throw "the queue is empty";
	return data[front+1];
}
