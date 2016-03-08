 ///
 /// @file    stack.cpp
 /// @iverson	(1564329410@qq.com)
 /// @date    2016-03-07 02:58:14
 ///
 
#include <iostream>
#include <strings.h>
using std::cout;
using std::endl;

template <typename T=int,int NUM=10>
class Queue{
	public:
		Queue();
		~Queue();
		bool empty();
		bool full();
		bool push(const T&);
		bool pop();
		T front();
	private:
		//使用循环数组
		int _tail;
		int _front;
		T _arr[NUM];
};

template <typename T,int NUM>
Queue<T,NUM>::Queue()
:_tail(0)
,_front(0)
{
	cout<<"Queue()"<<endl;
	bzero(_arr,sizeof(_arr));
}

template <typename T,int NUM>
Queue<T,NUM>::~Queue(){
	cout<<"~Queue()"<<endl;
}


template <typename T,int NUM>
bool Queue<T,NUM>::empty(){
	if(_front == _tail){
		return true;
	}else{
		return false;
	}
}


template <typename T,int NUM>
bool Queue<T,NUM>::full(){
	if(_front == (_tail + 1) % NUM){
		return true;
	}else{
		return false;
	}
}


template <typename T,int NUM>
bool Queue<T,NUM>::push(const T &num){
	if(!full()){
		_arr[_tail] = num;
		_tail = (_tail + 1) % NUM;
		return true;
	}else{
		return false;
	}
}


template <typename T,int NUM>
bool Queue<T,NUM>::pop(){
	if(!empty()){
		_front = (_front + 1) % NUM;
		return true;
	}else{
		return false;
	}
}


template <typename T,int NUM>
T Queue<T,NUM>::front(){
	return _arr[_front];
}

int main(void){
	Queue<int> st;
	cout<<"开始时st是否为空？-->"<<st.empty()<<endl;
	st.push(1);
	cout<<"入队一个元素后st是否为空？-->"<<st.empty()<<endl;

	for(int i=2; i!=11; i++){
		st.push(i);
	}

	cout<<"连续入队9个元素后st是否为满: "<<st.full()<<endl;
	cout<<"队列中的元素依次为:"<<endl;
	while(!st.empty()){
		cout<<st.front()<<" ";
		st.pop();
	}
	cout<<endl;
	return 0;
}
