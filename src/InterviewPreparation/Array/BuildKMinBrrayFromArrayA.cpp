/*
 * BuildKMinBrrayFromArrayA.cpp
 *
 *  Created on: Apr 13, 2013
 *      Author: root
 */



#include "constant.h"
#define MAXSIZE 100
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

Integer * minBArray(int A[],int n,int k){
	int *B=new int[n-k+1];
	DQueue Q;

	FOR(i,0,k){
		while(!Q.isEmpty()  && A[Q.rear()]>=A[i])
			Q.pop_rear();
		Q.insert_rear(i);
	}
	B[0]=A[Q.front()];
	FOR(i,k,n){
		while(!Q.isEmpty()  && A[Q.rear()]>=A[i])
					Q.pop_rear();
	     Q.insert_rear(i);
        while(!Q.isEmpty()&& (i-k)>=Q.front())
    	   Q.pop_front();
       B[i-k+1]=A[Q.front()];
	}
 return B;
}

void driver(){
  int A[]={1,2,3,4,5,6,1,2,6,9,5,2,8,10,0,15,6,23};
  int n=ARRAYSIZE(A);
  printArray(A,n);

  printArray( minBArray(A,n,3),n-2);

}


