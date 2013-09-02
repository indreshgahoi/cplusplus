/*
 * MyNextPermutation.cpp
 *
 *  Created on: Jan 14, 2013
 *      Author: indresh
 */

/*
 * 
 Link for understanding
 http://wordaligned.org/articles/next-permutation
 
 Name
Iterating Over All Permutations of an Array

Problem
You have an array of objects supporting comparison, and you want to iterate through all possible permutations of these objects.

Solution
Assuming that quite natural order of permutations is lexicographic order, you should be able to do just three things:
1) Generate the first permutation;
2) Get the next permutation from a given one;
3) Recognize the last permutation.

And then you can use this simple algorithm (in pseudo-code):

array a[n];
generate_first_permutation(a);
while (1) {
	// Do something with the array.
	if (is_last_permutation(a)) break;
 	get_next_permutation(a);
}
 *
 */

/* Theory:- To generate the next permutation we should find such an element ai
 *          (with maximal possible i) that can be replaced by such an element aj that
 *           ai< aj and i<j (with minimal possible aj under these constraints),
 *then swap ai and aj and reorder all elements with indices more than i non-decreasing.
 *
 *T(n)=A(n)*B(N)
 *A(n)=O(n!)
 *B(n)=O(n)
 *But over all Time Complexity=O(e*n!)=O(n)
 *So only useful for 10 t0 12 element(small value of n)
 */
#include<iostream>
#include<vector>
using namespace std;

void swap(int &a,int &b){
	int tmp=a;
	 a=b;
	 b=tmp;
}

bool MyNextPermutation(vector<int> &a){
 int size=a.size();
 int i=size-2;

 while(a[i]>=a[i+1]&& i>=0)i--;

 if(i<0){
	 i++;
	 while((size-i++-1)>0)
		 swap(a[i],a[size-i-1]);
	 return false;
 }

 int j=size-1;
 while(a[i]>=a[j])j--;
 swap(a[i],a[j]);//swap a[i] with a[j]
 // reorder the array from index i+1 to n-1
 i++;
 j=size-1;
 while(j>i)
	swap(a[i++],a[j--]);
 return true;
}

#define p(v) {for(int i=0;i<v.size();i++)cout<<" "<<v[i];cout<<"\n";}

int main(){
vector<int > a;
 /*
  * 3 2 4 3 1 to 3 3 1 2 4
  */
 #define pb push_back

  a.pb(3);
  a.pb(2);
  a.pb(4);
  a.pb(3);
  a.pb(1);
  p(a);
  MyNextPermutation(a);
  p(a);
  return 0;
}




























