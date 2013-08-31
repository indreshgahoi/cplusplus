/*
 * Point.cpp
 *
 *  Created on: Dec 7, 2012
 *      Author: indresh
 */
#include <iostream>

using namespace std;
class Point{
public:
	double x,y;
Point() {
	// TODO Auto-generated constructor stub
x=0.0;y=0.0;
cout<<"x= "<<x<<" y= "<<y<<" Default Constructor "<<endl;
}


Point(double nx, double ny){
	x=nx;y=ny;
cout<<"x= "<<x<<"y= "<<y<<" two parameter constructor"<<endl;
}
//Example of copy Constructor
Point(Point &o)
{
	x=o.x;y=o.y;
	cout<<"x= "<<x<<" y= "<<y<<"  Copy constructor"<<endl;
}


//Destructor is called when the class instance gets de-allocated

~Point()
{
	cout<<"Destructor invoked"<<endl;
}

};
int main(){
//	Point p(2.0,6.0);
	Point *pptr =new Point(4.0,8.0);
//	delete pptr;
// we call delete pptr because it's allocated by new


	if(true){
		Point m;
	}
	cout<<" m out of scope"<<endl;
	//Point q=p;
	return 0;
}

