/*
 * point.cpp
 *
 *  Created on: Jan 8, 2013
 *      Author: indresh
 */
#define EPS 1e-9
#define sqr(a) ((a)*(a))
class Point{

public:
	double x;
	double y;
	Point(double x,double y)
	{
		this->x=x;
		this->y=y;
	}
	Point()
	{
		x=0.0;
		y=0.0;
	}
	Point(Point &o){
		o.x=x;
		o.y=y;
	}
	~Point(){

	}
	double distance(Point p1,Point p2){
		return sqrt(sqr(p1.x-p2.x)+sqr(p1.y-p2.y));
	}

};


