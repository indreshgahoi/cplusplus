/*
 * ConvexPolyGun.c
 *
 *  Created on: Aug 14, 2013
 *      Author: Indresh Gahoi
 */


#include<stdio.h>
#define EPS 1e-6
struct Point
{
	double x;
	double y;
};

typedef struct Point Point;

/* polar angle of point p w.r.t to orgin (0,0)
 *  it returns Angle in range [0,2*pi)
 *  If Point is (0,0) return -1
 */
double polarAngle(Point p)
{
	if(fabs(p.x)<=EPS && fabs(p.y)<=EPS) return -1;
	if(fabs(p.x)<=EPS) return (p.y>EPS? 1:3)*acos(0);
	double theta=atan(1.0*p.y/p.x);
	if(fabs(p.x)>EPS) return (p.y>-EPS?theta:(4*acos(0)+theta));
	else return 2*acos(0)+theta;
}

