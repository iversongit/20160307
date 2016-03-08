 ///
 /// @file    nestedTemplate.cpp
 /// @iverson	(1564329410@qq.com)
 /// @date    2016-03-07 08:01:42
 ///
 
#include <iostream>
using std::cout;
using std::endl;

template <typename T1>
class Test
{
	public:
		template <class T2>
		T1 func(T2 b);
};

template <typename T1>
template <typename T2>
T1 Test<T1>::func(T2 b)
{
	return T1(b);
}

int main(void){
	Test<int> test;
	cout<<test.func(3.14f)<<endl;
	return 0;
}
