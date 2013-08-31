/*
 * IntegerArray.cpp
 *
 *  Created on: Dec 7, 2012
 *      Author: indresh
 */
#include<iostream>
using namespace std;
typedef int INT ;

template <typename T,typename U>
class IntegerArray{
public:
	T *data;
	U size;
	IntegerArray(U size):size(size)
	{
		data=new T[size];
		this->size=size;

	}
	IntegerArray(IntegerArray &o){
		cout<<"copy constructor invoked"<<endl;
		size=o.size;
		data=new T[size];
		for(U i=0;i<size;i++){
			data[i]=o.data[i];
		}
	}
	~IntegerArray(){
		cout<<"Destructor invoked \n"<<endl;

		delete[] data;

	}

    void fillByUser(){
		  for(U i=0;i<size;i++)
			  cin>>data[i];
	  }

    T& operator[](U i){
	  return data[i];
    }

   void printArray()
   {   cout<<endl;
	   for(U i=0;i<size;i++){
	   			  cout<<" data["<<i<<"]="<<data[i];
	   	  }
	    cout<<endl;
   }
};

int main(){

	IntegerArray<int,int> arr(2);
	arr[0]=5; arr[1]=arr[0]+arr[0]++;
	cout<<arr.data[0]<<endl<<endl;
	if(true)
	{
		IntegerArray<int,int> b=arr;
		cout<<b.data<<endl;
	}

	//cout<<endl<<arr.data[0]<<endl;
	cout<<arr[1]<<endl;
	//delete[] arr.data; can move this to destructor
    arr.printArray();
	return 0;
}
