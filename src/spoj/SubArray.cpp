/*
 * SubArray.cpp
 *
 *  Created on: Apr 13, 2013
 *      Author: root
 */

#include <iostream>


#include<algorithm>
#include<cstdio>
#include<climits>
#include<string>
#include <cstring>
#define FOR(_i,a,b) for(int _i=a;_i<b;_i++)
#define REP(_i,n)    for(int _i=0;_i<n;_i++)

#define ARRAYSIZE(A) (sizeof(A)/sizeof(A[0]))




#define MAXSIZE 100005

typedef int Integer ;


void printArray(int A[],size_t size){
	//printf("values= [");
   for(int i=0;i<size;i++)
	   printf("%d ",A[i]);
   printf("\n");
}


class DQueue{
public:
  DQueue();
 ~DQueue();
  void pop_front();
  void pop_rear();
  void insert_front(Integer);
  void insert_rear(Integer);
  Integer front();
  Integer rear();
  bool isEmpty();

private:
	int *data;
	int frnt,rer;
};

DQueue::DQueue(){
	this->data=new int[MAXSIZE];
	this->frnt=this->rer=-1;
}

DQueue::~DQueue(){
	delete []data;
}

bool DQueue::isEmpty(){
	return (this->frnt<0);
}

int DQueue::front(){
	return data[this->frnt];
}
int DQueue::rear(){
	return data[this->rer];
}
void DQueue::insert_front(Integer x){

	if(isEmpty()){
		this->frnt=this->rer=0;
		this->data[this->rer]=x;
		return;
	}
	if(this->frnt>0){
		(this->frnt)--;
	}
	else{
		this->frnt=MAXSIZE-1;
	}
	if(this->frnt==this->rer){
		std::cout<<"(Over Flow) DQueue is full"<<std::endl;
		exit(1);
	}
	this->data[this->frnt]=x;
}

void DQueue::insert_rear(Integer x){
	if(isEmpty()){
			this->frnt=this->rer=0;
			this->data[this->rer]=x;
			return;
		}
	this->rer=((this->rer)+1)%MAXSIZE;
	if(this->frnt==this->rer){
		std::cout<<"(Over Flow) DQueue is full"<<std::endl;
				exit(1);
	}
	this->data[this->rer]=x;
}


void DQueue::pop_front(){
	if(isEmpty()){
			std::cout<<"(Under Flow) Queue is empty"<<std::endl;
			exit(1);
		}


		if(this->frnt==this->rer){
			this->frnt=this->rer=-1;
		}
		else {
			this->frnt=(((this->frnt)+1)%MAXSIZE);
		}
}


void DQueue::pop_rear(){
	if(isEmpty()){
				std::cout<<"(Under Flow) Queue is empty"<<std::endl;
				exit(1);
			}

	if(this->frnt==this->rer){
		  this->frnt=this->rer=-1;
	}
	else if((this->rer)==MAXSIZE-1){
		this->rer=0;
	}
	else{
		this->rer--;
	}

}

Integer * maxBArray(int A[],int n,int k){
	int *B=new int[n-k+1];
	DQueue Q;

	FOR(i,0,k){
		while(!Q.isEmpty()  && A[Q.rear()]<=A[i])
			Q.pop_rear();
		Q.insert_rear(i);
	}
	B[0]=A[Q.front()];
	FOR(i,k,n){
		while(!Q.isEmpty()  && A[Q.rear()]<=A[i])
					Q.pop_rear();
	     Q.insert_rear(i);
        while(!Q.isEmpty()&& (i-k)>=Q.front())
    	   Q.pop_front();
       B[i-k+1]=A[Q.front()];
	}
 return B;
}


int main()
{
  int N,K;
  int i;
  int *A;
   scanf("%d",&N);
  A=new int[N];
  for(i=0;i<N;i++)
  {
    scanf("%d",&A[i]);
  }
  scanf("%d",&K);
  printArray(maxBArray(A,N,K),N-K+1);


return 0 ;
}



