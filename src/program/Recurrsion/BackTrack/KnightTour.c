/*
 * KnightTour.c
 *
 *  Created on: Oct 23, 2013
 *      Author: Indresh Gahoi
 */

#include<stdio.h>
#include <stdbool.h>
#define N 8


static inline bool isSafe(int x, int y,int chessBoard[][N]){

 return (x>=0 && x<N) && (y>=0 && y <N) && chessBoard[x][y]==-1;
}

bool SolveKT(int x,int y,int moveNo,int* x_move , int *y_move ,int chessBoard[][N]){

	int next_x,next_y,iter;
	if(moveNo==N*N)
		return true;

	for(iter = 0 ; iter<8 ; ++iter){
		next_x=x+x_move[iter];
		next_y=y+y_move[iter];

		if(isSafe(next_x,next_y,chessBoard)){
			chessBoard[next_x][next_y]=moveNo;
			if(SolveKT(next_x,next_y,moveNo+1,x_move,y_move,chessBoard))
				return true;
			else
				chessBoard[next_x][next_y]=-1; //BackTrack

		}
	}

	return false;
}


void print_solution(int chessBoard[][N]){
	int i,j;
		for(i=0 ; i < N ; ++i ){
			for( j =0 ; j< N ;++j)
				printf(" %d",chessBoard[i][j]);
         printf("\n");
		}

}

void KTSolver_Init(){

  int chessBoard[N][N];
  int x_move[] ={ 2, 1, -2,-1,-2,-1, 2, 1};
  int y_move[] ={ 1, 2,  1, 2,-1,-2,-1,-2};
  int i,j;

   for(i=0;i<N;++i)
	   for(j=0;j<N;++j)
		   chessBoard[i][j]=-1;
   chessBoard[0][0]=0;

   if(SolveKT(0,0,1,x_move,y_move,chessBoard)){
       printf("Solution is.....\n            ");
       print_solution(chessBoard);

   }
   else{
	   printf("Solution does not exit");
   }
}

int main(){
	KTSolver_Init();
	return 0;
}
