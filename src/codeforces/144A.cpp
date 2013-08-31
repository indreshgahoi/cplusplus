#include<iostream>
using namespace std;
int main()
{
    int n,x,y,res;

    cin>>n>>x>>y;

    res=(((n*y)+99)/100)-x;
    if(res>0)
     cout<<res<<endl;
    else
     cout<<"0\n";
     return 0;
}
