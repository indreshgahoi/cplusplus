#include <functional>
#include <algorithm>
#include <iostream>
#include <numeric>
#include <cassert>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <cstring>
#include <cmath>
#include <ctime>
using namespace std;
#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define fore(i, b, e) for (int i = (int)(b); i <= (int)(e); i++)
const int maxn = 100500;
#define pb push_back
#define mp make_pair
#define se second
#define fi first
typedef pair<int, int> pii;
typedef long long i64;

int len;
char s[1000005];


int * prefix()
{
   // int len=s.length();
    int * prefix_fn=new int[len+1];
    prefix_fn[1]=0;
    int k=0;

    fore(i,2,len){

    	while(k>0 && s[k]!=s[i-1]){
    		k=prefix_fn[k];
    	}

       if(s[k]==s[i-1])
       {
    	   k++;
       }

       prefix_fn[i]=k;

    }

    return prefix_fn;
}
/*
Given a string of length . Then the Z-function ("Z-function") from this string
   - is the array length , i-th element is equal to the greatest number of characters
   starting from a position i coinciding with the first character s .

In other words - is the greatest common prefix string and the second suffix.




*/
int * z_function()
{
  //  int len=s.length();
    int * z=new int[len];
    z[0]=len;
    int l=0,r=0;
    fore(i,1,len-1)
    {
        z[i]=0;
        if(i<=r)
          z[i]=(r-i+1<=z[i-l])? r-i+1:z[i-l];

          while(i+z[i]<len && s[z[i]]==s[i+z[i]])
           ++z[i];

          if(i+z[i]-1>r)
            l=i,r=i+z[i]-1;

       //cout<<"i="<<i<<"z["<<i<<"]"<<z[i]<<endl;
    }
    return z;
}

void reverse()
{
    //int len=s.length();
int    i=0,t=len;
    t--;
    while(i<t)
    {
     char tmp=s[t];
          s[t]=s[i];
          s[i]=tmp;
          i++;t--;
    }

}
int main()
{
    int t ,*z;

    scanf("%d",&t);
    while(t--)
    {
        //string s;

        int q;
        scanf("%s%d",s,&q);
        //cin>>q;
        len=strlen(s);
        reverse();

        z=z_function();
        //cout<<"hello";
       // cout<<s;
        fore(i,1,q)
           {
               int l;
               scanf("%d",&l);
               //cout<<"l="<<l<<" len-l="<<len-l<<endl;
               //cout<<(z[len-l])<<endl;
               printf("%d\n",z[len-l]);
           }
    }
    return 0;
}
