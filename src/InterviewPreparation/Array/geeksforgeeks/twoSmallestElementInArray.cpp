/*
 * twoSmallestElementInArray.cpp
 *
 *  Created on: Mar 30, 2013
 *      Author: indresh
 */

#include"constant.h"

pair<Integer,Integer> twosmallestElementInArray(Integer A[],size_t){
	if(size<2) return pair(-1,-1);
	Integer first,second;
	first=second=INT_MAX;
	REP(i,size){
		if(A[i]<first)
		{
			second=first;
			first=A[i];
		}
		else if(A[i]>first && A[i]<second ){
			second=A[i];
		}
	}
	return make_pair(first,second);
}


