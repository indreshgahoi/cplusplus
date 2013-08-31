#include<iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int mat[11][1001];
int size[11];
int height=0,n;


 void build (int v, int tl, int tr) {
	 if (tl == tr)
	 {
	     return;
	 }
	 else {
		 int tm = (tl + tr) / 2;


		 build (v+1, tl, tm);
		 build (v+1, tm + 1, tr);
		 for(int i=tm+1;i<=tr;i++){
		       mat[v][i]=tm; size[v]++;}
		       //printf("%d ",v);
               //printf("%d + %d =%d ",tm,i,i);
               //printf("\n");


		       if(v>height)
		           height=v;


	 }
 }

 void print_process()
 {
    printf("%d\n",height);
    for(int row=height;row>=1;row--){
        printf("%d ",size[row]);
      for(int col=1;col<=n;col++)
          {
              if(mat[row][col])
                printf("%d + %d =%d ",mat[row][col],col,col);

          }
        printf("\n");
    }
 }

 int main()
 {
     int t;
     scanf("%d",&t);
     while(t--)
     {   //memset(mat,0,sizeof(mat));
        // memset(size,0,sizeof(size));
         height=0;
         scanf("%d",&n);
         build(1,1,n);
         print_process();
     }
     return 0;
 }
