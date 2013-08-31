/*
 * UncountableWays.cpp
 *
 *  Created on: Dec 6, 2012
 *      Author: indresh
 */


#include<iostream>
//#define K 8000100
using namespace std;

int map[100][100];
long long int m=1000000007;
int N,M,A,B;
//long long int map[K];
long long int solve(int i, int j){
if((i==N && j==M)){
		map[i][j]=1;
	return 1;}
if((j<=(M-B) && i>=(N-A))|| i>N || j>M){
	map[i][j]=0;
	return 0;
}

if(map[i][j])
 return map[i][j];
map[i][j]=(2+solve(i+1,j)%m+solve(i,j+1)%m)%m;
return map[i][j];
}
int p[3][400005];
void pp()
{
	for(int i=1;i<=2;i++)
	{
		for(int j=1;j<=N;j++){
			cout<<" "<<p[i][j];
		}
		cout<<endl;
	}
	cout<<endl;
}

/*
 int solve( ){
    N++;M++;
	//int p[][N] =new int[2*N];
    int i=2,j=0;
    for(int l=1;l<=N-A;l++){
    	p[1][l]=1;

    }

    p[1][1]=0;
    pp();
	for(;i<=(M-B+1);i++){
		for(j=1;j<=N-A;j++)
		{    if(j==1){
			p[i&1?1:2][j]=1;cout<<"j="<<j<<endl<<endl;pp();
			   continue;}
			p[i&1?1:2][j]=p[i&1?1:2][j-1]+p[i&1?2:1][j];
			cout<<" i="<<i<<" j="<<j<<endl<<endl;pp();
		}
	}
	cout<<endl<<"i="<<i<<endl;
	   i--;

	   for(;j<=N;j++){
		   p[i&1?1:2][j]=p[i&1?1:2][j-1];
		   cout<<" i="<<i<<" j="<<j<<endl<<endl;pp();}
	   cout<<" fill"<<endl;
	   i++;
	for(;i<=M;i++){
			for(j=1;j<=N;j++)
			{    if(j==1){
				p[i&1?1:2][j]=1;cout<<"j="<<j<<endl<<endl;pp();
				   continue;}
				p[i&1?1:2][j]=p[i&1?1:2][j-1]+p[i&1?2:1][j];
				cout<<" i="<<i<<" j="<<j<<endl<<endl;pp();}
	}
	i--;
	int res=p[M&1? 1:2][N];
  //  delete[] p;
    return res;


}*/

int main(){
	int T;
	cin>>T;
     for(int i=0;i<100;i++)
    	 for(int j=0;j<100;j++)
    		  map[i][j]=0;
	while(T--){
		cin>>N>>M>>A>>B;
		//for(int i=0;i<=K;i++)map[i]=0l;
		A--;B--;
		cout<<solve(1,1)<<"\n";
		cout<<map[N][M];
		for(int i=1;i<=N+1;i++){
		    	 for(int j=1;j<=M+1;j++)
		    		cout<<" "<<map[i][j]<<" ";
		   cout<<endl;
		}
	}

	return 0;
}



