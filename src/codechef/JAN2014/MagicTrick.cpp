#include<iostream>
#include<sstream>
#include<fstream>
#include<cstdio>
#include<climits>
#include<pthread.h>
#include<sys/types.h>
#include<unistd.h>
#include<algorithm>
#include<string>
#include<cstring>
#include<set>
#include<vector>
#include<map>
#include<stack>
#include<queue>

using namespace std;

#define FOR(_i,a,b) for(int _i=a;_i<b;_i++)
#define REP(_i,n) for(int _i=0;_i<n;_i++)
#define debug(x) cout<<#x" "<<x<<" ";
#define nl cout<<"\n";
#define tab cout<<" ";

typedef    long long    Integer ;

/* input.txt
2
3
1000000000000000000 1000000000000000000 2000000000000000000
2 3 31
ARM
4
1 2 3 4
0 1 1000
AMAM
 *
 *
 *
 *
 */


#define modAdd(a,b,c)    ((a+b)%c)

Integer A ,B ,C ;




Integer ModMul(Integer x , Integer y)
{
     if(y==0) return 0 ;
     Integer res = ModMul(x,y>>1);
     res = (res + res) %C ;
     if(y&1)
    	 return (res + x) % C ;
     return res ;

}

void sovle(string &str ,Integer *arr ,int s , int e)
{
	 int len = str.size() ;
	 int i = 0 ;
	 int direction = 1 ;
	 Integer P = 0 , Q = 1 ;
	while(i < len)
	{
			switch(str[i])
			{
				case 'A': P = (P+A)%C ; break ;
				case 'M': P = ModMul(P,B) ; Q = ModMul(Q,B) ; break ;
				case 'R': direction=-direction ;swap(s,e) ; break ;
			}
            arr[s] = ModMul(arr[s]%C,Q) ;
            arr[s] = (arr[s]+P) %C ;
			cout<<arr[s]<<" ";
			s+=direction ;

		i++;
	}
}




#define MAX 10000
int main(){
	//freopen("input.txt", "rw", stdin);
	int T ,N,iter;
	Integer arr[MAX];
	string str ;
	cin>>T ;
	while(T--)
	{
		iter = 0 ;
		cin>>N ;
		while(N--)
		{
           cin>>arr[iter];
			iter++ ;
		}
		--iter;
		cin>>A>>B>>C ;
		cin>>str ;
		sovle(str,arr,0,iter) ;

		cout<<"\n" ;
	}

	return 0;
}
