#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define FORD(i,a,b) for(int i=a;i>=b;i--)
#define REP(i,n)    for(int i=0;i<n;i++)
#define mp(i,j)  make_pair(i,j)
#define pb(i)    push_back(i)
#define mclr(buf) memset(buf,0,sizeof(buf));
#define mset(buf,val) memset(buf,val,sizeof(buf));
#define N 2020
int m[N][N];
using namespace std;
inline int min (int a,int b,int c)
{
    int min ;
   min=(a<=b)?a:b;
   min=(min<=c)?min :c;
   return min;

}
int Edit_distance(string s1,string s2)
{
    int len1=s1.length();
    int len2=s2.length();
    m[0][0]=0;
    FOR(i,1,len2)
       m[0][i]=i;
    FOR(i,1,len1)
       m[i][0]=i;
    FOR(i,1,len1)
      FOR(j,1,len2)
      {
          int cost=0;
          if(s1[i-1]!=s2[j-1])
            cost=1;
          m[i][j]=min(m[i-1][j-1]+cost,
                      m[i-1][j]+1,
                      m[i][j-1]+1);
      }
  return m[len1][len2];
}

int main()
{
    int t;
    cin>>t;
    char s1[N],s2[N];
    while(t--)
    {
        cin>>s1>>s2;
        cout<<Edit_distance(s1,s2)<<endl;
    }

    return 0;
}
