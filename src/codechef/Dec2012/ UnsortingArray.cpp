/*
 *  UnsortingArray.cpp
 *
 *  Created on: Dec 6, 2012
 *      Author: indresh
 */
/*
#include <iostream>
#include <vector>
using namespace std;

void solve(int a[], int size){

	int i=0,j=0;

	if(size==1 || size==2 )
	{
		cout<<"-1\n";
	     return;
	}

	i=1;j=2;

	while(j<=size && a[i]==a[j]){
	i++,j++;
	}
	if(i==size){
		cout<<"-1\n";
        return ;
	}
	else if(a[i]>a[j])
	     {
		                 int l=1,p=i,q=j;
                           while(j<=size&&a[i]>=a[j]){
	                           l=1;
	                           if(a[i]!=a[j])
	                        	   p=i,q=j;
	                              while(j<=size && a[i]==a[j]){
	  	                          i++;j++;l=0;
	  	                           }



	                        if(l)
	                         i++,j++;
           }
  if(i==size){

  		cout<<p<<" "<<q<<"\n";
  		return;
  	}
  else{
	  //cout<<p<<" "<<j<<"\n";return;
  }
	}
	else if(a[i]<a[j]){
		int l=1;int p=i,q=j;
		 while(j<=size&&a[i]<=a[j]){
			 l=1;
			 if(a[i]!=a[j])
				 p=i,q=j;
			 while(j<=size && a[i]==a[j]){
			 	i++;j++;l=0;
			 	}

			  if(l)
			  i++,j++;
		  }
		  if(i==size){

		  	  cout<<p<<" "<<q<<"\n";return;
		  	}
		  else{
			  vector<pair<int,int> > temp(size+1);
			  for(int k=1;k<=size;k++){
				  temp.push_back(make_pair(a[i],k));
			  }
			  sort(a+1,a+size);
			  vector<pair<int,int> >::iterator it;
			  int m=1;
			  for(it=temp.begin(),m=1;it!=temp.end();it++,m++)
			  {
				  if((*it).first!=a[m] && (*(it+1). )
			  }

		  }
	}



*/
/*}
int main(){

	int T;
	cin>>T;
	int a[T+1];
	for(int i=1 ;i<=T;i++)
	{
		cin>>a[i];
	}
	solve(a,T);
	return 0;
}

*/
