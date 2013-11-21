/*
 * Fractional_KnapSack_Problem.c
 *
 *  Created on: Oct 26, 2013
 *      Author: Indresh Gahoi
 */

/* Given the weight of items along with its value and also the maximum weight that we can to take,
   we have to maximise the value we can get. Unlike 0-1 knapsack, here we are allowed to take fractional
   items. Hence this problem is called fractional knapsack
   */


#include<stdio.h>
#include <stdlib.h>

struct item	{
	int value;
	int weight;	  
};

typedef struct item Item; 

int CompareItems(const void *a ,const void *b){
  Item *i1 = (Item *) a;
  Item *i2 = (Item *) b;
  double rat1 = i1->value*1.0/i1->weight;
  double rat2 = i2->value*1.0/i2->weight;

  if(rat1>rat2) return -1;
  else if(rat1 < rat2) return 1;
  else return 0;
}


double Solve(Item *items , size_t size ,double bagCapacity){

  double MaxValue=0.0 ;
  size_t iter = 0;

  qsort(items , size , sizeof(Item) , CompareItems);

  for(iter = 0 ; iter < size ; ++iter){
	  if(bagCapacity >= items[iter].weight){
		  bagCapacity-=items[iter].weight;
		  MaxValue+=items[iter].value;
	  }
	  else{
		  MaxValue += bagCapacity * (items[iter].value*1.0/items[iter].weight);
		  break;
	  }
  }


  return MaxValue;
}

void test_greedy_knapsack_problem(){

	Item items[] ={{60,10},
					{100,20},
					{120,30},
					};
	double result;

	 result = Solve(items,sizeof(items)/sizeof(items[0]),50);

	 fprintf(stdout," result = %f \n",result);
}


int main(){
   test_greedy_knapsack_problem();
	return 0;
}

