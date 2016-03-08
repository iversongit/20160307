 ///
 /// @file    nestedTemplate2.cpp
 /// @iverson	(1564329410@qq.com)
 /// @date    2016-03-07 18:13:58
 ///
 
#include <iostream>
using std::cout;
using std::endl;

template <typename T>
class Outside{
	public:
		template <typename R>
			class Inside{
				public:
					Inside(R x);
					~Inside();
					void display();
				private:
					R _r;
			};
	public:
		Outside(T x);
		~Outside();
		void display();
	private:
		Inside<T> _t;
};

template <typename T>
Outside<T>::Outside(T x)
:_t(x)
{
	cout<<"Outside(T x)"<<endl;
}

template <typename T>
Outside<T>::~Outside(){
	cout<<"~Outside()"<<endl;
}

template <typename T>
void Outside<T>::display(){
	cout<<"Outside<T>::display()"<<endl;
	_t.display();
}

template <typename T>
template <typename R>
Outside<T>::Inside<R>::Inside(R x)
:_r(x)
{
	cout<<"Inside(R x)"<<endl;
}

template <typename T>
template <typename R>
Outside<T>::Inside<R>::~Inside(){
	cout<<"~Inside()"<<endl;
}

template <typename T>
template <typename R>
void Outside<T>::Inside<R>::display(){
	cout<<"Inside<R>::display()-->"<<_r<<endl;
}

int main(void){
	Outside<int>::Inside<float> test(3.14f);
	test.display();
	Outside<int> test2(2);
	test2.display();
	return 0;
}
