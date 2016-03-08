 ///
 /// @file    add.cpp
 /// @iverson	(1564329410@qq.com)
 /// @date    2016-03-07 02:20:40
 ///
 
#include <iostream>
#include <string.h>
using std::cout;
using std::endl;
//类似一个代码生成器
template <typename T> //函数模板
T add(const T &a,const T &b){
	return a > b ? a : b;
}

template <>  //模板特化
const char * add<const char *>(const char * const &a,const char * const &b){
	char *tmp = new char[strlen(a) + strlen(b) + 1];
	strcpy(tmp,a);
	strcat(tmp,b);
	return tmp;
}

//下述两个模板函数是由编译器根据参数通过函数模板推导出来的
#if 0
int add(int a,int b){
	return a + b;
}

double add(double a,double b){
	return a + b;
}
#endif

int main(void){
	cout<<"add(2,3)--->"<<add(6,8)<<endl;
	cout<<"add(3.1,3.4)--->"<<add(6.1,6.2)<<endl;
	const char * s1 = "hi";
	const char * s2 = "man";
	cout<<"add(s1,s2)--->"<<add(s1,s2)<<endl;
	return 0;
}
