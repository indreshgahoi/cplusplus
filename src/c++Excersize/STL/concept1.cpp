/*
 * concept1.cpp
 *
 *  Created on: Jun 19, 2013
 *      Author: Indresh Gahoi
 */

#include<iostream>
#include <boost/scope_exit.hpp>

class A
{
public:
	int a;
	A(int a):a(a){

	}
};

int main()
{
	A *a1=new A(2);
	A *a2=new A(3);

	std::cout<<"a1 data ="<<a1->a<<std::endl;
	std::cout<<"a2 data ="<<a2->a<<std::endl;
	*a1=*a2;
	std::cout<<"After assignment a1 data ="<<a1->a<<std::endl;

	return 0;
}
