#include<stdio.h>
#define M 1001
int main(){
	long long a[M][M],t,n,i,j=3;
	long long s[M];
	i=2;
	while(i<M){
		a[2][i]=1;
		s[i]=2;
		i++;
	}
	i=3;
	s[1]=1;
	while(j<M){
		i=3;
		while(i<j){
			a[i][j]=((a[i-1][j-1])+(a[i][j-1])*(i-1))%1000000007;
			s[j]=(s[j]+a[i][j]*(i))%1000000007;
			i++;
		}
		a[i][j]=1;
		s[j]=(s[j]+j)%1000000007;
		j++;
	}
	scanf("%lld",&t);
	while(t--){
		scanf("%lld",&n);
		printf("%lld\n",s[n]);
	}
	return 0;
}
