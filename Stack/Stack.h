//Author	: yqtao
//date		: 2016.09.09
//Email		: yqtao@whu.edu.cn
/*
Implement my own stack
*/
const int stackSize = 100;
template<typename T>
class Stack
{
public:
	Stack() { top = -1; }
	bool Empty() { return top == -1; }
	void Push(T x);
	void Pop();
	T GetTop();
	int Size();
private:
	T data[stackSize];
	int top;
};
template<typename T>
void Stack<T>::Push(T x)
{
	if (top >= stackSize - 1)
		throw "out of range";
	top++;
	data[top] = x;
}
template<typename T>
void Stack<T>::Pop() {
	T temp = data[top];
	top--;
}
template<typename T>
T Stack<T>::GetTop() {
	if (top <= -1)
		throw "the stack is empty";
	return data[top];
}
template<typename T>
int Stack<T>::Size() {
	return top+1;
}