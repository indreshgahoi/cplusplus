/*
ID: indresh1
PROG: ride
LANG: C++
*/
#include<iostream>
#include <fstream>
#include <string>
#include<cstdio>
using namespace std;
typedef int Integer;

Integer T;

Integer main(){
	    ofstream fout ("ride.out");
	    ifstream fin ("ride.in");
Integer mul1=1,mul2=1;
	char comet[6],group[6];
	char *c=comet,*g=group;
	fin>>c;
	while((*(c))!='\0')
      mul1=(mul1*(*c++-'A'+1))%47;

   fin>>g;
	while(*(g)!='\0')
      mul2=(mul2*(*g++-'A'+1))%47;
	if(mul1==mul2)
		fout<<"GO"<<endl;
	else
		fout<<"STAY"<<endl;
	return 0;
}



