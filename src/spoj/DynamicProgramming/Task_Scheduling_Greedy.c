/*
 * Task_Scheduling_Greedy.c
 *
 *  Created on: Oct 27, 2013
 *      Author: Indresh Gahoi
 */

#include<stdio.h>
#include<stdlib.h>

typedef struct event {
	int start_time;
	int end_time;
	int event_number;
} event;

typedef struct array {
	event *list;
	size_t size;
} Array;


/* compare events to sort events according  finish time  */
int compare(const void * o1 , const void * o2){

	event *e1 = (event *) o1 , *e2 = (event * )o2;
 return e1->end_time- e2->end_time;
}

Array  Solve(event *T , size_t size){
   Array resarr;
   size_t iter , previous_event=0 ,possible_events=0;;
   resarr.list = (event *) malloc(sizeof(struct event)*size);
   resarr.size = 0;
   qsort(T,size,sizeof(event),compare);
   possible_events=0;
   resarr.list[possible_events++]=T[0];
   previous_event = 0;
   for(iter = 1 ; iter < size ; ++ iter){
      if(T[iter].start_time >= resarr.list[previous_event].end_time){
    	  resarr.list[possible_events++]=T[iter];
    	  previous_event = possible_events -1;
      }
   }
   resarr.size = possible_events;
   return resarr;
}

void print_array(Array arr){
	size_t iter = 0;
	printf("event number |start time |end time \n");

	for( iter =0 ; iter < arr.size ; ++iter){
	  printf(" %d             %d          %d    \n",arr.list[iter].event_number,arr.list[iter].start_time,arr.list[iter].end_time);
	}
	printf("\n Total no of event attend = %d \n",arr.size);
}

void test_task_schedule(){
    int N , iter;
    event *T;
    Array arr;
	freopen("input.txt","r",stdin);
	scanf("%d",&N);
	T = (event *) malloc(sizeof(event) * N);

	for(iter = 0 ; iter < N ; ++iter){
		T[iter].event_number = iter;
		scanf("%d",&T[iter].start_time);
		scanf("%d",&T[iter].end_time);
	}

	arr = Solve(T,N);
	print_array(arr);
}

int main(){

	test_task_schedule();
	return 0;
}
