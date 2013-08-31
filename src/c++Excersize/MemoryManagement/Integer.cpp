/*
 * Integer.cpp
 *
 *  Created on: Dec 7, 2012
 *      Author: indresh
 */

#include "iostream"
using namespace std;
class Integer{
public:
	int val;
/*	Integer() {
	//this->i=v;
		val=0;
	cout<<" Integer Default Constructor "<<endl;
}*/
	//use default arguments

	Integer(int val=0) {
		this->val=val;

		cout<<" Integer Constructor With arg "<<val<<endl;
	}
};

class IntegerWrapper
{
public:
	Integer val;
	IntegerWrapper()
	{

		cout<<"IntegerWrapper Default Constructor"<<endl;
	}
};
int main(){

	Integer a;

/*
   Can invoke single-parameter constructor via assignment to
   the appropriate type
*/
	Integer b=5;

	Integer arr[3]={Integer(1),Integer(2),Integer(3)};// ok

	//Integer arr[3]; //call using default constructor if not then error
//	if(true){
//		Integer b=a;
//	}
IntegerWrapper q;

int **t;
t=new  int*[5];
 t[0]=new int[5];
 t[1]=new int[5];
 t[2]=new int[5];
 t[3]=new int[5];
 t[4]=new int[5];
 t[4][4]=8;
 cout<<" ans="<<t[4][4];

	return 0;
}


