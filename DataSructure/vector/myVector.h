// Date   : 2016.07.22
// Author : yqtao
// https://github.com/yqtaowhu
/********************************
* 实现自己的vector
* 注意vector中的迭代器只是普通的指针，因此不必进行重载操作
* 它是Random Access Iterator
********************************/
#ifndef MY_VECTOR_H
#define MY_VECTOR_H

#include <memory>
#include <iostream>
#include <algorithm>
template <class T, class Alloc=std::allocator<T>> class myVector
{
public:
	//vector的嵌套类型
	typedef T						value_type;
	typedef value_type*				iterator;
	typedef const value_type*		const_iterator;
	typedef value_type&				reference;
	typedef value_type*				pointer;
	typedef	size_t					size_type;    
	typedef ptrdiff_t				difference_type; //表示两个迭代器之间的距离 ,c++内置定义 typedef int ptrdiff_t;
protected:
	std::allocator<value_type> _alloc;  //空间分配器,这里使用stl标准写法，而不是sgi标准写法
	iterator _start;					//数组的首元素
	iterator _end;					//目前使用空间的尾
	iterator _end_of_storage;			//目前可用空间的尾
public:
	myVector() :_start(0), _end(0), _end_of_storage(0){}//默认构造函数
	myVector(size_type n, const T& value);
	myVector(size_type n);  
	myVector(iterator first, iterator last);
	myVector(const myVector& v);			//复制构造函数
	myVector& operator=(const myVector& rhs);  //赋值操作符函数
	~myVector() { _destroy(); }

	
	iterator begin() { return _start; }
	iterator end()	 { return _end; }
	const_iterator cbegin() const { return _start; }    //常量迭代器
	const_iterator cend() const { return _end; }

	size_type size()  { return size_type(end() - begin()); }  //注意转换成size_t类型
	size_type capacity() { return size_type(_end_of_storage - begin()); }
	bool empty() { return begin() == end(); }
	void swap(myVector &other);
	

	reference front() { return *begin(); }
	reference back() { return *(end() - 1); }
	reference operator[] (size_type n) { return *(begin() + n); }           //重载[],这样可以用a[n]进行访问元素

																			//删除数组中的元素，并且释放内存
	 
	void insert_aux(iterator positon, const T& x);  //一个插入辅助的函数，在向量为满的时候用到
	void push_back(const T& value);
	void pop_back();
	void insert(iterator position, size_type n, const T& x);  

	iterator erase(iterator position);
	iterator erase(iterator first, iterator last);  //删除[first,last)的元素
	void clear() { erase(begin(), end()); }
private:
	
	void _destroy();   //删除数组中的元素，并且释放内存
	
};



template <class T, class Alloc = std::allocator<T>>
myVector<T, Alloc>::myVector(size_type n, const T& value) {
	_start = _alloc.allocate(n);						 //调用配置器函数分配内存
	std::uninitialized_fill(_start, _start + n, value);  //调用c++内置函数进行初始化
	_end = _end_of_storage = _start + n;                 //修改迭代器的指针
}
//构造函数n 个0
template <class T, class Alloc = std::allocator<T>>
myVector<T, Alloc>::myVector(size_type n) {
	_start = _alloc.allocate(n);
	std::uninitialized_fill(_start, _start + n, 0);
	_end = _end_of_storage = _start + n;              
}
//
template <class T, class Alloc = std::allocator<T>>
myVector<T, Alloc>::myVector(iterator first, iterator last) {
	_start=_alloc.allocate(last - first);  //分配空间
	_end=_end_of_storage=std::uninitialized_copy(first, last, _start);
}
//
template <class T, class Alloc = std::allocator<T>>
myVector<T, Alloc>::myVector(const myVector& v) {
	size_type n= v.cend() - v.cbegin();
	_start=_alloc.allocate(n);    //分配空间
	_end = _end_of_storage = std::uninitialized_copy(v.cbegin(), v.cend(), _start);
}
//
template <class T, class Alloc = std::allocator<T>>
void myVector<T, Alloc>::swap(myVector &other) {
		std::swap(_start, other._start);
		std::swap(_end, other._end);
		std::swap(_end_of_storage, other._end_of_storage);
}
//
template <class T, class Alloc = std::allocator<T>>
myVector<T, Alloc> &myVector<T, Alloc>::operator=(const myVector &rhs) {
	if (this == &rhs)
		return *this;
	size_type n = rhs.cend() - rhs.cbegin();
	_start=_alloc.allocate(n);
	_end = _end_of_storage = std::uninitialized_copy(rhs.cbegin(), rhs.cend(), _start);
}
//

template <class T, class Alloc = std::allocator<T>>
void myVector<T, Alloc>::insert(iterator position, size_type n, const T& x) {
	if (n >= 0) {
		if (_end_of_storage - _end >= n) {   //剩余空间够用,分两种情况
			T x_copy = x;
			const size_type elem_after = _end - position;   //计算插入点之后的元素个数
			iterator old_end = _end;       
			if (elem_after >n) {
				uninitialized_copy(_end - n, _end, _end);
				_end = _end + n;        //将尾端后移
				copy_backward(position, old_end - n, old_end);
				fill(position, position + n, x_copy);
			}
			else {                      //要插入的元素大于等于插入点之后元素
				uninitialized_fill_n(_end, n - elem_after, x_copy);
				_end += n - elem_after;
				uninitialized_copy(position, old_end, _end);
				_end += elem_after;
				fill(position, old_end, x_copy);
			}
		}
		else {            //如果剩余空间不足
			const size_type old_size = size();
			const size_type len = old_size + max(old_size, n);
			iterator new_start = _alloc.allocate(len);
			iterator new_end = new_start;
			new_end =uninitialized_copy(_start, position , new_start);   //将position之前的元素复制到新容器
			new_end=uninitialized_fill_n(new_end, n, x);    //插入元素
			new_end=uninitialized_copy(position, _end, new_end);
			_destroy();   //调用成员函数进行释放空间
			//重新调整迭代器，使其指向新的位置
			_start = new_start;
			_end = new_end;
			_end_of_storage = new_start + len;
		}
	}
}
//
template <class T, class Alloc = std::allocator<T>>
void myVector<T, Alloc>::insert_aux(iterator positon, const T& x) {
	if (_end != _end_of_storage) {

	}
	else {
		const size_type old_size = size();                    //需要注意，如果开始长度为0
		const size_type len = old_size ? 2 * old_size : 1;    //则配置长度1，否则，加倍
		iterator new_start = _alloc.allocate(len);            //重新分配空间
		iterator new_end = new_start;
	    
		new_end = uninitialized_copy(_start, positon, new_start);   //对于push_back来说position=_end,将其拷贝出来
	    _alloc.construct(new_end, x);                     //插入元素
		++new_end;
		new_end = uninitialized_copy(positon, _end, new_end);     //将插入点后的元素也拷贝过来

		_destroy();                    //执行自定义函数
		//调整迭代器，指向新的指针

		//重新调整迭代器，使其指向新的位置
		_start = new_start;
		_end = new_end;
		_end_of_storage = new_start + len;

	
	}
}
//
template <class T, class Alloc = std::allocator<T>>
void myVector<T, Alloc>::push_back(const T& value) {
	if (_end != _end_of_storage) {        //如果还有剩余的空间
		_alloc.construct(_end, value);        //在_end处调用配置器插入value
		++_end;                               //迭代器后移
	}
	else
		insert_aux(end(), value);                //如果空间已满		
}
//
template <class T, class Alloc = std::allocator<T>>
void myVector<T, Alloc>::pop_back() {
	--_end;               //这里要注意的是，删除尾部，要让_end先移动到最后一个元素
	_alloc.destroy(_end);
}
//
template <class T, class Alloc = std::allocator<T>>
typename myVector<T, Alloc>::iterator myVector<T, Alloc>::erase(iterator position) {
	if (position + 1 != end())   //也就是说要删除的这个元素不是最后一个元素
		copy(position + 1, end(), position);
	--_end;
	_alloc.destroy(_end);
	return position;
}
//
template <class T, class Alloc = std::allocator<T>>
typename myVector<T, Alloc>::iterator myVector<T, Alloc>::erase(iterator first, iterator last) {
	difference_type left = _end - last;   
	std::copy(last, _end, first);         //first last avail 向前迁移元素
	iterator it(first + left);
	while (_end != it)                   //需要析构，有可能不需要析构，这要看在last后元素与删除元素的比较
		_alloc.destroy(--_end);
	return first;
}


template <class T, class Alloc = std::allocator<T>>
void myVector<T, Alloc>::_destroy() {
	//先执行析构函数
	if (_start)
	{
		iterator it(_end); //初始
		while (it != _start)
			_alloc.destroy(--it);
	}

	//释放内存
	_alloc.deallocate(_start, _end_of_storage - _start);
	_start= _end_of_storage = _end = NULL;
}
#endif
