/*
 * Problem156.cpp
 *
 *  Created on: Dec 16, 2012
 *      Author: indresh
 */
#include <iostream>
#include <utility>
#include <algorithm>
using namespace std;
int main(){

int n;
cin>>n;
int a1=0,a2=0,a3=0;
int i=0;int n1;
while(true){
	cin>>n1;
	a1+=n1;
	i++;
	if(i>=n)
		break;
	cin>>n1;
		a2+=n1;
		i++;
		if(i>=n)
			break;
		cin>>n1;
			a3+=n1;
			i++;
			if(i>=n)
				break;
}

int m=max(max(a1,a2),a3);
if(m==a1)
	cout<<"chest";
else if(a2==m)
	cout<<"biceps";
else
	cout<<"back";

return 0;
}

