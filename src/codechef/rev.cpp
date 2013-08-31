#include<iostream>
#include<cstdio>

using namespace std;
int main()
{
    int i,t,l=1;
    char c[5];
    scanf("%d",&t);
    while(t--){
       scanf("%s",c);
       l=1;
       for(i=4;i>=0;i--){
        if(c[i] == '0' && l==1)
         {
             continue;

             }
        else{ l=0;printf("%c",c[i]);}}
        cout<<"\n"<<endl;
    }
  return 0;
}


