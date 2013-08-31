/*
 * sqrtX.cpp
 *
 *  Created on: Mar 28, 2013
 *      Author: indresh
 */

#include <iostream>
#include<cstdio>
#include <sstream>
using namespace std;
/*
 *  newton rapson method
 *   f(x)=(x)^2 -x
 *   f'(x)=(2*x)
 *   xn+1=(xn)-(f(xn)/f'(xn));
 *         =>(xn)-(xn^2-x)/2*xn;
 */
#define EPS 1e-6
int sqrt(int x) {
        double x1=x,x2=x-0.1;
        while((x2-x1)>EPS){
        	x1=x2;
        	x2=x1-((x1*x1)-x)/(2*x1);
        }
        return int(x2);
    }
int main(){
 return 0;
}



