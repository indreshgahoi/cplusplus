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


double polarAngle(const point &p)
{
    if(fabs(p.x)<=EPS && fabs(p.y)<=EPS) return -1.0;
    if(fabs(p.x)<=EPS) return (p.y>EPS? 1.0:3.0) *acos(0);
    double theta=atan(p.y/p.x);
    
    if(p.x>EPS) return (p.y>=-EPS)?theta:(4*acos(0)+theta);
    return (2*acos(0)+theta);
}

/* To detect the the point is either clock wise (right turn) or
* counter clock wise (left turn) or colinear
* retrun 1 counter clock wise
* return 2 clock wise
* return 0 colinear
*/
int ccw(const point &p,const point &q,const point &r)
{
    point a={p.x-r.x,p.y-r.y};
    point b={q.x-r.x,q.y-r.y};
    // a=ax i+ ay j
    // b=bx i + by j
    // a*b= ax*by - ay*bx cross product
    double cp= a.x*b.y-a.y*b.x;
    if(cp>0) return 1;
    if(cp<0) return 2;
    else return 0;
}
