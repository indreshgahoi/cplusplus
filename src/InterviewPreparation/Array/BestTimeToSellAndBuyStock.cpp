/*
 * BestTimeToSellAndBuyStock.cpp
 *
 *  Created on: Jan 19, 2013
 *      Author: indresh
 */

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/* LeedCode Question
 * Say you have an array for which the ith element
 * is the price of a given stock on day i.
 * Design an algorithm to find the maximum profit. You may complete at most two
 * transactions.
 *
 */
/* Find iand j that maximizes (Aj-Ai) ,where i<j
 * only single transaction
 */




#define maX(a,b)  ((a)>(b)?(a):(b))

int getBestTime(vector<int> &prices){
	int min=0,maxDiff=0;
	int buy,sell;
	for(int i=0;i<prices.size();i++){
		if(prices[i]<prices[min]){
		min=i;}
		if((prices[i]-prices[min])>maxDiff)
		{
            maxDiff=prices[i]-prices[min];
            buy=min;
            sell=i;
		}

	}
	return maxDiff;
}
/*
 *  when allowed exactly two transaction
 */
int maxProfitii(vector<int> &prices) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
     vector<int> future(prices.size(),0);
     vector<int> history(prices.size(),0);
     if(prices.size()<=1)return 0;
     int currMin=0,currMax=prices.size()-1,maxProfit=0;
     for(int i=1;i<prices.size();i++){
         if(prices[i]<prices[currMin])
          currMin=i;
          history[i]=max(history[i-1],prices[i]-prices[currMin]);
     }
      for(int i=prices.size()-2;i<prices.size();i--){
         if(prices[i]>prices[currMax])
          currMax=i;
          future[i]=max(future[i+1],-prices[i]+prices[currMax]);
          maxProfit=max(maxProfit,future[i]+history[i]);
     }
     return maxProfit;
    }
//when allow at most one transaction
int maxProfit(vector<int> &prices) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
      for(vector<int>::iterator it=prices.begin()+1;it!=prices.end();it++)
      {
    	  *it=*it-*(it-1);
      }
      int max_So_far=0,max_sum=0;
      for(vector<int>::iterator it=prices.begin();it!=prices.end();it++){
    	  max_So_far=maX(0,max_So_far+*it);
    	  max_sum=maX(max_So_far,max_sum);
      }
      return max_sum;
    }
//when allow maximum transaction
int maxProfitiii(vector<int> &prices) {
       // Start typing your C/C++ solution below
       // DO NOT write int main() function
      if(prices.size()<2) return 0;
      int result=0;
      for(int i=1;i<prices.size();i++)
       {
           if(prices[i]-prices[i-1]>0)
            result+=prices[i]-prices[i-1];
       }
       return result;
   }
int main(){
	vector<int> prices;
	int T;
	cin>>T;
	int n;
	while(T--){
		cin>>n;
		prices.push_back(n);
	}
	cout<<"max_profit="<<maxProfit(prices)<<endl;
	return 0;
}



