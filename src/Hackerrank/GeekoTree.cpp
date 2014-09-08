#include <iostream>
#include<cmath>
using namespace std;


int ans(int a , int b , int res){
	    	  if (b==0) return 0;
	    	   int k = a % b ;
	    	   cout<<" k : "<<k<<"\n";
	    	    return k + ans(a/b,k,res+k);
}


int main()
{

    int t ;

    cin>>t ;
    while(t-- > 0 ){
    	int n ;
    	int k ;
    	cin >> n ;
    	cin >> k ;

    	int nodes = ((int)pow(n+.0,k+1.0) - 1 )/( n -1);


    	int res = ans(nodes,10,0);
    	cout<<res<<"\n" ;


    }
    return 0 ;
}
