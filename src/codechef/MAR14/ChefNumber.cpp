/*
 * ChefNumber.cpp
 *
 *  Created on: Mar 9, 2014
 *      Author: indresh
 */


#include<iostream>
#include<cstdio>

using namespace std ;


int main()
{
   int T ;
   scanf("%d",&T);

   int size ;
   while(T--)
   {
	   scanf("%d",&size);

	   long long count[3] = {0} ;
       int x ;
	   for(int iter = 0 ; iter < size ; ++iter)
	   {
		   scanf("%d",&x);
		   if(x < 3) count[x]++ ;
	   }

	   long long total = (((long long)size) * (size-1) ) / 2;
	   long long faultPair = 0 ;
	   for(int i = 0 ; i < 3 ; ++i){
		   faultPair += (count[i]*(count[i]-1)) / 2 ;
	   }
	   faultPair += count[0] *(size-count[0]) + count[1]*(size-count[0]-count[1]) ;

	   long long res = total - faultPair ;
	   printf("%lld\n",res) ;
   }
  return 0 ;
}
