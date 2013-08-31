/*
 * MapPractice.cpp
 *
 *  Created on: Dec 11, 2012
 *      Author: indresh
 */


#include <iostream>
#include<map>
using namespace std;
long long int count=10;

long long int inc(){
	return count++;
}
int main(){

	map<long long int,long long int> mymap;

	//mymap();
mymap[23]=inc();
mymap[90]=inc();

cout<<"map value"<<mymap[23]<<" "<<mymap[90]<<endl;
	return 0;
}


