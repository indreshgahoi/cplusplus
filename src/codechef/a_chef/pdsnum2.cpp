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
bool n[100000000]={false};
int cn[10000000];

struct node
{
    int sum;
    int mul;
    int id;
    int num;
    struct node *child[10];
}*tree;

int cnt=0;
queue<struct node*> myqueue1,myqueue2;

char buff[10];


void itoa(int num)
{ int i=0;
    while(num)
    {buff[i]=num%10+48;
     num/=10;
     i++;
    }
   buff[i]='\0';
}

void pds(int N,int pd)
{
        int g,i;
        int cd;
        if(N>100000000)
           return;
          if(pd==0)
          {
             if(N*10<100000000)
                 n[N]=true;
             for(i=0;i<=9;i++)
                {
                    pds(N*10+i,0);

                }
          }
        else
         {
           for(i=0;i<=9;i++)
              {
                g=N*10+i;
                cd=pd*i;
                pds(g,cd);
              }
        }
}

static void rec_permutation(char *a,int start,int last){

         int j;
         char set[10]={0};
         char temp;
         if(start==last)
         {
             n[atoi(a)]=true;

         }
          else{

               for(j=start;j<=last;j++){
                  // if( *(a+start)!=*(a+j))
                   if(!set[*(a+j)-'0']){
                     set[*(a+j)-'0']=1;

                     a[start] ^= a[j] ^= a[start] ^= a[j];
                    temp=*(a+start);
                   *(a+start)=*(a+j);
                   *(a+j)=temp;

                  rec_permutation(a,start+1,last);
                     a[start] ^= a[j] ^= a[start] ^= a[j];
                    temp=*(a+start);
                    *(a+start)=*(a+j);
                    *(a+j)=temp;
                  }



               }
          }
  }


void create(int d)
{

    tree=new node;

    for(int i=1;i<=9;i++)
    {
      node* temp =tree->child[i]=new node;
      myqueue2.push(temp);
      temp->mul=i;
      temp->sum=i;
      temp->id=i;
      temp->num=i;
      n[i]=true;

   }


    for(int i=2;i<=d;i++)
    {
        if(i & 1)
        {
            while(!myqueue1.empty())
        {
             node *temp=myqueue1.front();
             myqueue1.pop();
            for(int j=temp->id;j<=9;j++)   //j=temp->id to 9 for optmize
            {
              node* temp1 =temp->child[j]=new node;
              myqueue2.push(temp1);
              temp1->mul=(temp->mul)*j;
              temp1->sum=(temp->sum)+j;
              temp1->id=j;
              temp1->num=temp->num*10+j;
             if( temp1->mul%temp1->sum==0)
              {
                  itoa(temp1->num);
                  rec_permutation(buff,0,i-1);
              }

        } free(temp);
        }


    }
        else
        {

            while(!myqueue2.empty())
        {
             node *temp=myqueue2.front();
             myqueue2.pop();
            for(int j=temp->id;j<=9;j++)
            {
              node* temp1 =temp->child[j]=new node;
              myqueue1.push(temp1);
              temp1->mul=(temp->mul)*j;
              temp1->sum=(temp->sum)+j;
              temp1->id=j;
              temp1->num=temp->num*10+j;
             if(temp1->mul%temp1->sum==0)
              {
                      itoa(temp1->num);
                      rec_permutation(buff,0,i-1);
              }

           }
           free(temp);
        }


        }


    }

}

int main()
{
InitFASTIO();
  // n=new (100000000,0);
for(int i=1;i<=9;i++)
   {
   pds(i,i);
   }


int nk;
create(7);
cnt=0;
for(int i=1;i<500000000;i++)
  if(n[i])
       {
           cnt++;
           if(cnt<500000000)
           cn[cnt]=i;

      }


while(true)
 {
     nk=input_int();

    if(nk==0)
       break;
    if(nk<500000000)
       printf("%d\n",cn[nk]);
    else
      printf("%d\n",1000000000+nk-cn[499999999]);



 }
return 0;
}
