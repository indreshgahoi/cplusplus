/*
 * FindBiggestToArrangeNubers.cpp
 * run command
 * g++ /Algorithm/src/InterviewPreparation/Array/geeksforgeeks/FindBiggestToArrangeNubers.cpp -o /usr/build/Main.o
 *
 *  Created on: Nov 12, 2013
 *      Author: Indresh Gahoi
 */


/* Link :- http://www.geeksforgeeks.org/given-an-array-of-numbers-arrange-the-numbers-to-form-the-biggest-number/
 *
 * Question :- Arrange given numbers to form the biggest number
 *
 * Given an array of numbers, arrange them in a way that yields the largest value.
 * For example, if the given numbers are {54, 546, 548, 60},
 * the arrangement 6054854654 gives the largest value.
 * And if the given numbers are {1, 34, 3, 98, 9, 76, 45, 4},
 * then the arrangement 998764543431 gives the largest value.
 *
 */

#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
#include<algorithm>

using namespace std ;

/*
 *  Actually we are looking for order which makes the combine number maximum ;
 *
 *  so method to decide the order
 *
 *   X Y    X
 *
 *   XY > YX  XY else YX
 *
 *
 *
 */

template<class T>
ostream& operator<<(ostream &out,const vector<T>& V){
	out<<"[";
	for(typename vector<T>::const_iterator it=V.begin();it!=V.end();it++){
	 out<<" "<<*it;
	}
	out<<"]"<<endl;
	return out;
}




int decideOrder(string x ,string y)
{
	string XY = x.append(y);
	string YX = y.append(x);
	return XY.compare(YX) > 0 ? 1 : 0 ;
}


void printLargest(vector<string> &numbers)
{
    sort(numbers.begin(),numbers.end(),decideOrder);
    cout<<numbers;
}


void test()
{
	vector<string> arr;

	    //output should be 6054854654
	    arr.push_back("54");
	    arr.push_back("546");
	    arr.push_back("548");
	    arr.push_back("60");
	    cout<<arr;
	    printLargest(arr);

	    // output should be 777776
	    arr.clear();
	    arr.push_back("7");
	    arr.push_back("776");
	    arr.push_back("7");
	    arr.push_back("7");
	    cout<<arr;
	    printLargest(arr);

	    //output should be 998764543431
	    arr.clear();
	    arr.push_back("1");
	    arr.push_back("34");
	    arr.push_back("3");
	    arr.push_back("98");
	    arr.push_back("9");
	    arr.push_back("76");
	    arr.push_back("45");
	    arr.push_back("4");
	    cout<<arr;
	    printLargest(arr);



}


int main()
{
    test();
    cout<<"\n";
	return 0 ;
}



