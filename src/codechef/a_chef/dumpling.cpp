#include <iostream>
#include <cstdio>
#include <cctype>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <sstream>
#include <fstream>
#include <ctime>
#include <cassert>
#include <string.h>
using namespace std;
#define GI ({int t;scanf("%d",&t);t;})
#define GL ({LL t;scanf("%lld",&t);t;})
#define GD ({double t;scanf("%lf",&t);t;})
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define REP(i,n) FOR(i,0,n)
#define ROF(i,a,b) for(int i=a;i>b;i--)
#define SET(x,a) memset(x,a,sizeof(x));
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define tr(i,a) for( __typeof__(a.begin()) i=a.begin();i!=a.end();i++)
#define pb push_back
#define sz(a) (int)(a.size())
#define INF 100000000000000000LL
#define EPS (double)1e-9
#define is istringstream
#define os ostringstream
#define lb lower_bound
#define ub upper_bound
#define bs binary_search
typedef unsigned long long ULL;
typedef long long LL;
typedef set <int> si;
typedef pair< int,int > ii;
typedef pair< int, ii > pi;
typedef vector< ii > vii;
typedef vector < vii > vvii;
typedef vector< int > vi;
typedef vector< vi > vvi;
//char ch;


// FAST I/O
#define MAXX 10000000
char *ipos, *opos, InpFile[MAXX], OutFile[MAXX], DIP[30];

inline int input_int(int flag = 0){

   while(*ipos <= 32) ++ipos;

     if ( flag )
     return (*ipos++ - '0');

     int x = 0, neg = 0; char c;

     while( true )
      {

        c = *ipos++;
        if(c == '-')
         neg = 1;
        else{
           if(c <= 32)
            return neg ? -x : x;
           x = (x << 1) + (x << 3) + c - '0';
        }
     }
  }
inline LL input_LL(int flag = 0){

while(*ipos <= 32)
  ++ipos;
if ( flag )
  return (*ipos++ - '0');

 LL x = 0, neg = 0; char c;

 while( true )
  {

    c = *ipos++;
    if(c == '-')
      neg = 1;
    else{
       if(c <= 32)
       return neg ? -x : x;
      x = (x << 1) + (x << 3) + c - '0';
     }
  }
}

inline void input_st(char *s)
{
  while(*ipos <= 32) ++ipos;
   int pos = 0;char c;

   while( true )
   {
       c = *ipos++;
       if(c <= 32)
        {
            s[pos] = '\0';
             break;
        }
       else
        s[pos++] = c;
}
}
inline void output(int x)
{
    int y;
    int dig = 0;
    while(x || !dig)
    {
        y = x / 10;
        DIP[dig++] = x - ((y << 3) + (y << 1)) + '0'; x = y;
    }

   while(dig--)
    *opos++ = DIP[dig];
}
inline void InitFASTIO()
{
   ipos = InpFile;
   opos = OutFile;
   fread_unlocked(InpFile, MAXX, 1, stdin);
}
inline void FlushFASTIO()
{

  fwrite_unlocked(OutFile, opos - OutFile, 1, stdout);
}

//End of FAST I/O
long long int gcd(long long int a,long long int b)
{
    if(b==0)return a;
    /*while(b!=0)
    {
      if(a>b)
      a=a-b;
      else
      b=b-a;	
    }*/
    return gcd(b,a%b);
}
int main()
{
    InitFASTIO();
   long long int a,b,c,d,k,x,y,t,i,ans;
   //scanf("%lld",&t);
   t=input_LL();
   while(t--)
   {
     ans=0;
    // scanf("%lld%lld%lld%lld%lld",&a,&b,&c,&d,&k);
     a=input_LL();
     b=input_LL();
     c=input_LL();
     d=input_LL();
     k=input_LL();
     //x=abs(a-b);y=abs(c-d);
     x=a>b?gcd(a,b):gcd(b,a);


   FlushFASTIO();
   return 0;
}
