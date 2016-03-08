 ///
 /// @file    sequential2.cpp
 /// @iverson	(1564329410@qq.com)
 /// @date    2016-03-08 00:59:35
 ///
 
#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

void display(vector<int> &vecInt){
	vector<int>::iterator it;
	for(it=vecInt.begin(); it != vecInt.end(); ++it){
		cout<<*it<<" ";
	}
	cout<<endl;
}

int main(void)
{
	vector<int> vecInt(5,0);
	display(vecInt);
	cout<<"------------------"<<endl;

	vector<int>::iterator it = vecInt.end();
	it = vecInt.insert(it,1);
	display(vecInt);
	cout<<"------------------"<<endl;

	vecInt.insert(it,2,3);
	display(vecInt);
	cout<<"------------------"<<endl;

	it = vecInt.begin();
	int arr[3] = {6,7,8};
	vecInt.insert(it,arr,arr+3);
	display(vecInt);

	return 0;
}
