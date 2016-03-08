 ///
 /// @file    template.cpp
 /// @iverson	(1564329410@qq.com)
 /// @date    2016-03-06 21:39:16
 ///
 
#include <iostream>
#define MAX(x,y) (x > y ? x : y)

using std::endl;
using std::cout;

//以求两数中的较大数为例，采用的三种方法如下所示：
//宏定义的方法
#if 0
int main(void){
	cout<<MAX(4,7)<<endl;
	cout<<MAX(2.4,5.6)<<endl;
	return 0;
}
#endif

//函数重载的方法

#if 0
int max(int a,int b){
	return a > b ? a : b;
}

double max(double a,double b){
	return a > b ? a : b;
}

int main(void){
	int a = 1,b = 2;
	double c = 1.1,d = 2.1; 
	cout<<max(a,b)<<endl;
	cout<<max(c,d)<<endl;
	return 0;
}
#endif

//模板的方法
template<typename T>
T max(T a,T b){
	return a > b ? a : b;
}

int main(void){
	cout<<max(1,2)<<endl;
	cout<<max(1.1,2.1)<<endl;
	return 0;
}
