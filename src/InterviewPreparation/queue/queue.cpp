/*
 * queue.cpp
 *
 *  Created on: Apr 13, 2013
 *      Author: root
 */

#include<iostream>

#define MAXSIZE 100
typedef int Integer;

class Queue{
public:
  Queue();
  ~Queue();
  void insert(Integer);
  void pop();
  Integer frnt();
  bool isEmpty();

private:
	Integer *data;
	int front,rear;
};



Queue::Queue(){
   data=new int[MAXSIZE];
   this->rear=this->front=-1;
}

Queue::~Queue(){
	delete []data;
}

bool Queue::isEmpty(){
	return (this->front<0);
}

Integer Queue::frnt(){
	if(isEmpty()){
      std::cerr<<"Queue is empty"<<std::endl;
      exit(1);
	}
	return this->data[this->front];
}

void Queue::pop(){
	if(isEmpty()){
		std::cerr<<"(Under Flow) Queue is empty"<<std::endl;
		exit(1);
	}


	if(this->front==this->rear){
		this->front=this->rear=-1;
	}
	else {
		this->front=(((this->front)+1)%MAXSIZE);
	}
}


void Queue::insert(Integer x){

	if(isEmpty()){
		this->front=this->rear=0;
		this->data[this->rear]=x;
		return ;
	}

	this->rear=((this->rear)+1)%MAXSIZE;
	if(this->rear==this->front){
		std::cerr<<"(Over Flow) Queue is Full"<<std::endl;
		exit(1);
	}
	else{
		this->data[this->rear]=x;
	}
}


