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
 *  Theory : -                f(x) = x^2 - w     f'(x) = 2 x
 *   |                        old gess g
 *   \                        new gess g'
 *   |\                       y = mx + b
 *   |_\f(g)                  m at g  is f'(g)
 *   | |\                     let us suppose origin is translated at g then find
 *   | | \                     /_\ g  y = 0   then b = f(g)
 *   | |  \                      0 = f'(g)(g'-g) +  f(g)
 *   |_|__ \______________________  g' = g - f(g)/f'(g)
 *     g<-->g'
 *       delta g
 *
 *
 *
 *
 * Link :
 *  	http://www.arl.wustl.edu/~jst/cse/131/Notes/SquareRoot/sqrt.htmlFinding the New Guess
Let's consider the new guess first. We have:



 *
 */




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

/*
 *  This is log(n) solution
 */





class Solution {
public:
int sqrt(int x) {
  // Start typing your C/C++ solution below
  // DO NOT write int main() function
  if(x<=1) return x;

  int left=0, right=x, mid;

  while( (right-left)>1 )
  {
    mid=left+(right-left)/2;

    if(mid==x/mid)
      return mid;
    else if(x/mid < mid)
      right=mid;
    else
      left=mid;
  }

  return left;
}
};








