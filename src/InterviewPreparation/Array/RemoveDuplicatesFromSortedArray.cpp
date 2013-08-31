/*
 * RemoveDuplicatesFromSortedArray.cpp
 *
 *  Created on: Mar 24, 2013
 *      Author: indresh
 */

#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
/*
Follow up for "Remove Duplicates":
What if duplicates are allowed at most twice?

For example,
Given sorted array A = [1,1,1,2,2,3],

Your function should return length = 5, and A is now [1,1,2,2,3].

*/

int removeDuplicates(int A[], int n) {
     if(n<3) return n;
     int cur=0;
     for(int i=1;i<n;i++)
     {
    	 if(A[i]==A[i-1]){
              int x=i;
              cur++;
              A[cur]=A[i];
              i++;

              while(A[x]==A[i] && i<n){
            	  i++;
              }

         }
    	 if(i!=n){
    	 cur++;
    	 A[cur]=A[i];}
      }
 return cur+1;
   }

/*
 * second approach
 */

int removeDuplicatesV2(int A[], int n) {
     if(n<3) return n;
     int cur=0;
     int c=1;
     for(int i=1;i<n;i++)
     {
       if(A[i]!=A[cur]){
    	   A[++cur]=A[i];
    	   c=1;
       }
       else{

    	   if(c<2){
    		   c++;
    		   A[++cur]=A[i];
    	   }

       }
     }
 return cur+1;
   }

/*
 *  third Approach
 */
//it takes 84 milli secs
int removeDuplicatesV3(int A[], int n) {
     if(n<3) return n;
     int cur=1;
     for(int i=2;i<n;i++)
     {
        if(!(A[i]==A[cur] && A[i]==A[cur-1])){
         A[++cur]=A[i];
        }

     }
     return cur+1;
   }


void printArray(int A[],int cur){
	cout<<"[";
	for(int i=0;i<cur;i++){
		cout<<" "<<A[i];
	}
	cout<<" ]"<<endl;
}

int main(){
	int A[]={1,1,1};
	int n=sizeof(A)/sizeof(int);
	cout<<"n="<<n<<endl;
	int cur=removeDuplicates(A,n);
	printArray(A,cur);
	return 0;
}

