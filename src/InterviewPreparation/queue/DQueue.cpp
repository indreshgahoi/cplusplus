/*
 * DQueue.cpp
 *
 *  Created on: Apr 13, 2013
 *      Author: root
 */

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
		std::cerr<<"(Over Flow) DQueue is full"<<std::endl;
		exit(1);
	}
	this>data[this->frnt]=x;
}

void DQueue::insert_rear(Integer x){
	if(isEmpty()){
			this->frnt=this->rer=0;
			this->data[this->rer]=x;
			return;
		}
	this->rer=((this->rer)+1)%MAXSIZE;
	if(this->frnt==this->rer){
		std::cerr<<"(Over Flow) DQueue is full"<<std::endl;
				exit(1);
	}
	this->data[this->rer]=x;
}


void DQueue::pop_front(){
	if(isEmpty()){
			std::cerr<<"(Under Flow) Queue is empty"<<std::endl;
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
				std::cerr<<"(Under Flow) Queue is empty"<<std::endl;
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
