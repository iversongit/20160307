 ///
 /// @file    singletonAutorelease.cpp
 /// @iverson	(1564329410@qq.com)
 /// @date    2016-03-04 23:48:49
 ///
#include <stdio.h>
#include <iostream>
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
	private:
		Singleton();
		~Singleton();
	private:
		class AutoRelease{
			public:
				AutoRelease();
				~AutoRelease();
		};
	private:
		static T* _pInstance;
		static AutoRelease _autorelease;
};

template <typename T>
T* Singleton<T>::_pInstance = NULL;

template <typename T>
typename Singleton<T>::AutoRelease Singleton<T>::_autorelease;

template <typename T>
Singleton<T>::Singleton(){
	cout<<"Singleton()"<<endl;
}

template <typename T>
Singleton<T>::~Singleton(){
	cout<<"~Singleton()"<<endl;
}

template <typename T>
T* Singleton<T>::getInstance(){
	_autorelease; //实例化_autorelease
	if(_pInstance == NULL){
		_pInstance = new T;
	}
	return _pInstance;
}

template <typename T>
Singleton<T>::AutoRelease::AutoRelease(){
	cout<<"AutoRelease()"<<endl;
}

template <typename T>
Singleton<T>::AutoRelease::~AutoRelease(){
	cout<<"~AutoRelease()"<<endl;
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
