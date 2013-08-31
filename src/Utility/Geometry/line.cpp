/*
 * line.cpp
 *
 *  Created on: Jan 8, 2013
 *      Author: indresh
 */

#include "point.cpp"
 class line{
	/*
	 *  ax+by+c=0;
	 */
 public:
	 double a;
	 double b;
	 double c;
	 //
	// line by two point
	 line(Point p1,Point p2){
		 if(fabs(p1.x-p2.x)<=EPS){
			 a=1.0;
			 b=0.0;
			 c=-(p1.x);
		 }
		 else{
			  b=1;
			  a=-(p1.y-p2-y)/(p1.x-p2.x);
			  c=-(a*p1.x+b*p1.y);
		 }
	 }
   //line by point p1 and slope m
	 line(Point p1,double m){
		 a=-m;
		 b=1.0;
		 c=-(a*p1.x+b*p1.y);
	 }
	 bool parallelQ(line l){
		 return (fabs((a/l.a)-(b/l.b))<=EPS);
	 }
	 bool samelineQ(line l){
	  return(parallelQ(l) && fabs(c/l.c)<EPS);
	 }
  //intersection point of two line
	 Point intersectionPoint(line l)
	 {
		 Point res;

		 if(samelineQ(l)){
			 std::cout<<" all point are intersection";
		 }
		 else if(parallelQ(l))
		 {
			 std::cout<<" never intersect";
		 }
		 res.x=(l.b*c-b*l.c)/(l.a*b-a*l.b);
		 if(fabs(b/a)>EPS)//vertical line
		 res.y=-(a*res.x+c)/b;
		 else
		 res.y=-(l.a*res.x+l.c)/l.b;
       return res;
	 }
	 // return a point on line l which is closet to a given point
	//
	 Point closetPoint(Point p1){
		 Point res;
		 if(fabs(b/a)<=EPS)//Vertical line
		 {
			res.x=-(c/a);
			res.y=p1.y;

		 }
		 else if(fabs(a/b)<=EPS) // Horizontal line
		 {
			res.y=-(c/b);
			res.x=p1.x;
		 }
		 line perp=new line(p1,b/a);
		 res=intersectionPoint(perp);
		 return res;
	 }
 };


