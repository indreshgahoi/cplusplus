#include<stdio.h>

static int col;

void setboard(int board[][col],int row,int qcol){
    board[row][qcol]=2;
}
void unsetboard(int board[][col],int row,int qcol){
    board[row][qcol]=0;
}



int issafe(int board[][col], int qrow, int qcol)
{
    return ((qrow >=0 && qrow< col) &&
           (qcol>=0 && qcol< col)&&
           (board[qrow][qcol]==0));
}
void display_Board(int board[][col])
{ int i,j;
   for(i=0;i<col;i++){
     for(j=0;j<col;j++){
       if(board[i][j]==2)
        printf(" * ");
        else
        printf(" %d ",board[i][j]);
     }
        printf("\n");
   }
}

int Solve(int board[][col],int qrow,int qcol)
{
    if ((qcol == col-1) && (qrow == col-1))
    {
    	printf("path is:\n");
    	setboard(board, qrow, qcol);
    	return 1;
    } // base case
   else
   { // There are four possible wat to travel up, down, back ,forward but not cross
  if (issafe(board, qrow, qcol)) {
            setboard(board, qrow, qcol);
            printf("set:\n\n");
            display_Board(board);
            printf("\n\n");
 if (Solve(board, qrow + 1,qcol))
 {//down
	 printf("1:\n\n");
	 display_Board(board);
	 printf("\n\n");
     return 1;
 }

 else if (Solve(board, qrow ,qcol+1))
 {//forward
	 printf("2:\n\n");
	 display_Board(board);
	 printf("\n\n");
     return 1;
 }
 else if (Solve(board, qrow-1 ,qcol))
 {//up
	 printf("3:\n\n");
	 display_Board(board);
	 printf("\n\n");
     return 1;
 }
 else if (Solve(board, qrow ,qcol-1))
 { //backword
	 printf("4:\n\n");
	 display_Board(board);
	 printf("\n\n");//
     return 1;
 }
  unsetboard(board,qrow , qcol);
  printf("unset:\n\n");
  display_Board(board);
  printf("\n\n");
 }
}
return 0;
}


     

void init_Board(int board[][col])
{ int i,j,k;
   for(i=0;i<col;i++){
     for(j=0;j<col;j++)
	 {scanf("%d",&k);
       board[i][j]=k;
     }
	 
	 }
}

int main(){

printf("\nEnter the no of column:");
scanf("%d",&col);
int board[col][col];
init_Board(board);
Solve(board,0,0);
display_Board(board);
getch();

}
