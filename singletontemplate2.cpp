 ///
 /// @file    singletonAutorelease.cpp
 /// @iverson	(1564329410@qq.com)
 /// @date    2016-03-04 23:48:49
 ///
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <pthread.h>
using std::cout;
using std::endl;

class Myclass{
	public:
		Myclass(){
			cout<<"Myclass()"<<endl;
		}

		~Myclass(){
			cout<<"~Myclass()"<<endl;	
		}
};

template <typename T>
class Singleton{
	public:
		static T* getInstance();
		static void init();
		static void destroy();
	private:
		Singleton();
		~Singleton();
	private:
		static T* _pInstance;
		static pthread_once_t _once;
};

template <typename T>
T* Singleton<T>::_pInstance = NULL;

template <typename T>
pthread_once_t Singleton<T>::_once = PTHREAD_ONCE_INIT;

template <typename T>
Singleton<T>::Singleton(){
	cout<<"Singleton()"<<endl;
}

template <typename T>
Singleton<T>::~Singleton(){
	cout<<"~Singleton()"<<endl;
}

template <typename T>
void Singleton<T>::init(){
	/*atexit函数注册的函数在main退出的时候会被自动调用*/
	atexit(destroy);
	if(_pInstance == NULL){//线程安全
		_pInstance = new T;
	}
}

template <typename T>
T* Singleton<T>::getInstance(){
	/*pthread_once函数能保证其注册的函数在多线程环境中只被执行一次*/
	pthread_once(&_once,init);
	return _pInstance;
}

template <typename T>
void Singleton<T>::destroy(){
	if(_pInstance != NULL){
		delete _pInstance;
	}
}

int main(void){
	Myclass *s1 = Singleton<Myclass>::getInstance();
	Myclass *s2 = Singleton<Myclass>::getInstance();
	printf("the address of s1 : %p\n",s1);
	printf("the address of s2 : %p\n",s2);
	return 0;
}
