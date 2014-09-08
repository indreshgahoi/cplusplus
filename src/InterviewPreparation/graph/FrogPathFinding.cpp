/*
 * FrogPathFinding.cpp
 * run command
 * g++ /media/program/cprogram/git_repo/Algorithm/src/InterviewPreparation/graph/FrogPathFinding.cpp -o /usr/build/Main.o
 *
 *  Created on: Feb 11, 2014
 *      Author: Indresh Gahoi
 */

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
#define REP(_i,n)    for(int _i=0;_i<n;_i++)
#define debug(x) cout<<#x" "<<x;
#define nl cout<<"\n";
#define tab cout<<"		";
void driver();
void printArray(int A[],size_t size){
	printf("values= [");
	for(int i=0;i<size-1;i++)
		printf("%d ,",A[i]);
	printf("%d]\n",A[size-1]);
}
template<class T>
ostream& operator<<(ostream &out,const vector<T>& V){
	out<<"[";
	for(typename vector<T>::const_iterator it=V.begin();it!=V.end();it++){
		out<<" "<<*it;
	}
	out<<"]"<<endl;
	return out;
}
void getInput(vector<int> &v)
{
#define ARRAYSIZE(A) sizeof(A)/sizeof(A[0])
	int arr[] = {-1,-1,-1,1,1};
	int size = ARRAYSIZE(arr) ;
	for(int iter = 0 ; iter < size ; ++iter)
	{
		v.push_back(arr[iter]);
	}
}
/*
Link :-  
Question :-

Given a 2-D MxN matrix having each value as difficulty for the block.
A frog is starting from a point Matrix[0][0] and
will have to reach Matrix[M-1][N-1].
It can jump any step in one go [ 1, 2, ..... M-1]
horizontally OR [ 1,2,3,.... N-1] vertically Each difficulty value is positive.
Write code to give path trace for frog.
Two structure to use -

struct node
{
 int x;
 int y;
 struct node *next;
};

struct path
{
	int difficulty;
	struct node *pathlink;
}

 */


struct node
{
	int x;
	int y;
	struct node *next;
};
struct path
{
	int difficulty;
	struct node *pathlink;
};
void main()
{
	int i,m,n,j;
	printf("m:?");
	scanf("%d",&m);
	printf("\nn:?");
	scanf("%d",&n);
	struct node *root,*temp;
	struct path *map=(struct path*)malloc(sizeof(struct path*));
	root=NULL;
	int a[m][n],dif[m][n],k,l,min,minx,miny;
	struct node index[m][n];
	printf("difficulties:?\n");
	for(int i=n-1;i>=0;i--)
	{
		for(int j=n-1;j>=0;j--)
		{
			min=619;
			temp=(struct node*)malloc(sizeof(struct node*));
			index[i][j]=temp;
			temp->x=i;
			temp->y=j; k=i+1;
			l=j+1;
			while(l!=n)
			{
				if(dif[i][l])
					next=NULL;
				else
				{
					dif[i][j]=a[i][j]+a[minx][miny];
					temp->next=index[minx][miny];
				}
			}
		}
		map->pathlink=temp;
		i=0;
		while(temp!=NULL)
		{
			printf("%d ",a[temp->x][temp->y]);
			temp=temp->next; i++;
		}
	}
}

