 ///
 /// @file    stack.cpp
 /// @iverson	(1564329410@qq.com)
 /// @date    2016-03-07 02:58:14
 ///
 
#include <iostream>
#include <string>
#include <sstream>
using std::cout;
using std::endl;
using std::string;

template <typename T=int,int NUM=10>
class Stack{
	public:
		Stack();
		~Stack();
		bool empty();
		bool full();
		bool push(const T&);
		bool pop();
		T top();
	private:
		int _top;
		T _arr[NUM];
};

template <typename T,int NUM>
Stack<T,NUM>::Stack()
:_top(-1)
{
	cout<<"Stack()"<<endl;
}

template <typename T,int NUM>
Stack<T,NUM>::~Stack(){
	cout<<"~Stack()"<<endl;
}


template <typename T,int NUM>
bool Stack<T,NUM>::empty(){
	if(_top == -1){
		return true;
	}else{
		return false;
	}
}


template <typename T,int NUM>
bool Stack<T,NUM>::full(){
	if(_top == (NUM - 1)){
		return true;
	}else{
		return false;
	}
}


template <typename T,int NUM>
bool Stack<T,NUM>::push(const T &obj){
	if(!full()){
		++_top;
		_arr[_top] = obj;
		return true;
	}else{
		return false;
	}
}


template <typename T,int NUM>
bool Stack<T,NUM>::pop(){
	if(!empty()){
		--_top;
		return true;
	}else{
		return false;
	}
}


template <typename T,int NUM>
T Stack<T,NUM>::top(){
	return _arr[_top];
}

int main(void){
	Stack<string,5> st;
	cout<<"开始时st是否为空？-->"<<st.empty()<<endl;
	st.push("hello");
	cout<<"压入一个元素后st是否为空？-->"<<st.empty()<<endl;
	for(int i=1; i<5; i++){
		std::ostringstream oss;
		oss<<"ival ="<<i;
		st.push(oss.str());
	}
	cout<<"再压入4个元素后st是否为满？-->"<<st.full()<<endl;
	cout<<"堆栈中的元素依次为："<<endl;
	while(!st.empty()){
		cout<<st.top()<<" ";
		st.pop();
	}
	cout<<endl;
	return 0;
}
