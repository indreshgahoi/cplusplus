#include<iostream>
#include <algorithm>
#include <cstring>
using namespace std;
#define MAX 100010
#define MOD 1000000007
long long C[MAX];
int A[MAX];
int main(){
   int n,k;
   int t;
   cin>>t;
   while(t--){
       cin>>n>>k;
       for(int i =0; i<n; i++){
           cin>>A[i];
       }

       sort(A, A+n);
       memset(C, 1, sizeof(C));
       C[0] = 1;
       for(int i =1; i<=(n-k); i++) {
           C[i] *= C[i-1] * (n-k + i);
           C[i] %= MOD;
       }

       long long ret = 0;
       for(int i =0; i<n; i++){
    	   ret = ret + A[i]*C[n-k];
           ret %= MOD;
       }

       cout<<ret<<endl;
   }

   return 0;
}
