#include<iostream>
using namespace std;
int f[100];
int a[100];
int solve(int n)
{
    if(n==0)
     return 0;
    if(n==1)
     return a[n];
   if(f[n]!=-100)
    return f[n];
 f[n]=max(a[n]+solve(n-2),solve(n-1));
 return f[n];
}


int main()
{
    for(int i=1;i<100;i++)
     f[i]=-100;
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
     cin>>a[i];
    cout<<"result= "<<solve(n);
   for(int i=1;i<=n;i++)
    cout<<"  "<<f[i];
    return 0;
}
