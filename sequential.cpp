 ///
 /// @file    sequential.cpp
 /// @iverson	(1564329410@qq.com)
 /// @date    2016-03-07 21:45:09
 ///
 
#include <iostream>
#include <vector>
#include <deque>
#include <list>
using std::cout;
using std::endl;
using std::deque;
using std::list;

int main(void){
	int a[5] = {1,2,3,4,5};
	/*迭代器的范围是一个左闭右开的区间【）*/
	deque<int> doubleque(a,a+5);

	/*随机访问迭代器*/
	for(int i=0; i<doubleque.size(); i++){
		cout<<doubleque[i]<<" ";
	}

	cout<<endl;

	deque<int>::iterator it;
	/*双向访问迭代器*/
	for(it = doubleque.begin();it != doubleque.end();++it){
		cout<<*it<<" ";
	}
	cout<<endl;

	list<float> flist(3,5.1);
	list<float>::iterator lit;
	for(lit = flist.begin(); lit != flist.end(); ++lit){
		(*lit) += 2;
		cout<<*lit<<" ";
	}

	cout<<endl;

	list<float> flist2(4,8.8);
	flist2.swap(flist);

	/*list不支持下标随机访问，只能通过迭代器双向遍历*/
	for(lit=flist.begin(); lit != flist.end(); ++lit){
		cout<<*lit<<" ";
	}
	cout<<endl;
	return 0;
}
