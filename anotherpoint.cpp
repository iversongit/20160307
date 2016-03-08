 ///
 /// @file    anotherpoint.cpp
 /// @iverson	(1564329410@qq.com)
 /// @date    2016-03-07 02:45:32
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class Point{
	public:
		Point(int x=0,int y=0)
		:_x(x)
		,_y(y)
		{
			cout<<"Point(int,int)"<<endl;
		}

		~Point(){
			cout<<"~Point()"<<endl;
		}
		operator int(){
			return _x * _y;
		}
	private:
		int _x;
		int _y;
};

int main(void){
	Point p(2,2);
	cout<<p<<endl;
	return 0;
}
