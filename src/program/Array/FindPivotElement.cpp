/*
 * FindPivotElement.cpp

 *
 *  Created on: Dec 21, 2012
 *      Author: indresh
 */
#include <stdio.h>
#include <iostream>
using namespace std;
int getPivotIdx(int a[],int l,int r){

	int m;
	while(l<r){



        if(a[l]<a[r])
        	break;
        m=(l+r)>>1;
		if(a[l]>a[r]){

        if(a[m]<a[r])
			r=m-1;
		else
			l=m+1;
		}



	}
	if(a[m]<a[m+1])
		return m;

	return m+1;
}
int getElementIdxIdx(int a[],int l,int r,int find){

	int m;
	while(l<=r){
		m=(l+r)>>1;
        if(a[m]==find)
        	return m;
         if(a[l]==a[m] &&(l+1)==r){ //do linear search
        	 l++;

         }
         else if(a[l]<a[m]){
        	 if(find>a[m] || find<a[l])
        		 l=m+1;
        	 else
        		 r=m-1;
         }
         else if(find<a[m] || find>a[r])
        	  r=m-1;
             else
            	 l=m+1;
         cout<<" l="<<l<<" m="<<m<<" r="<<r<<endl;
}

	 return -1;

}

int search(int a[], int l, int u, int x) {


	while (l <= u) {
         int m = (l + u) / 2;
            if (x == a[m]) {
              return m;
            }
            else if (a[l] <= a[m]) {
                   if (x > a[m]) {
                        l=m+1;
                    } else if (x >=a [l]) {
                               u = m-1;
                             }
                           else {
                               l = m+1;
                              }
                }
            else if (x < a[m]) u = m-1;
            else if (x <= a[u]) l = m+1;
            else u = m-1;
           }
          return -1;
}

int main(){
	int a[]={5,6,7,8,9, 10,11,12,13,14,15,16,17,1,2,3,4};
	printf("%d",a[getPivotIdx(a,0,16)]);
	cout<<endl<<"output 1="<<getElementIdxIdx(a,0,16,17);
	cout<<endl<<"output 2="<<search(a,0,16,17);
}

