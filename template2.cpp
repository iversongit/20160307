 ///
 /// @file    template2.cpp
 /// @iverson	(1564329410@qq.com)
 /// @date    2016-03-06 22:01:34
 ///
 
#include <iostream>
using std::cout;
using std::endl;

//模板参数有两种类型
//1.类型参数
//2.非类型参数，必须是int型
template<typename T,int NUM>
T fun(T a){
	return a*NUM;
}

int main(void){
	//显式实例化
	//add（10，20）诸如此类的为隐式实例化
	cout<<"fun<int,10>(6)-->"<<fun<int,10>(6)<<endl;
	return 0;
}
