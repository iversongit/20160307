 ///
 /// @file    template3.cpp
 /// @iverson	(1564329410@qq.com)
 /// @date    2016-03-07 03:37:57
 ///
 
#include <iostream>
using std::cout;
using std::endl;

/*普通函数优先于函数模板的执行*/
int max(const int &a,const int &b){
	cout<<"Nomal max"<<endl;
	return a > b ? a : b;
}

template <typename T>
T max(const T &a,const T &b){
	cout<<"Template max"<<endl;
	return a > b ? a : b;
}

int main(void){
	/*调用普通函数*/
	cout<<"max(4,5)-->"<<max(4,5)<<endl;
	/*调用模版函数*/
	cout<<"max('a','b')-->"<<max('a','b')<<endl;
	int ret1 = max('a','b');
	cout<<"ret1 = "<<ret1<<endl;
	int ret2 = max<char>(4,5);
	cout<<"ret2 = "<<ret2<<endl;
	return 0;
}
